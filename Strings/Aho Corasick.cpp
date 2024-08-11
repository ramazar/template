struct Node{
    int link, par, ch, Link, cnt;
    //string tmp = "";
    bool ok;
    vector < int > ind, nxt, go;
    Node(){
        cnt = 0;
        ok = 0;
        nxt.assign(26, -1);
        go.assign(26, -1);
        link = Link = 0;
    }
};
vector < Node > trie;
int ans[500005];
void add(string &s, int i){
    int cur = 0;
    string op = "";
    for(auto i: s){
        if(trie[cur].nxt[i - 'a'] == -1){
            trie[cur].nxt[i - 'a'] = (int)trie.size();
            trie.push_back(Node());
            trie[(int)trie.size() - 1].par = cur;
            trie[(int)trie.size() - 1].ch = i - 'a';
        }
        cur = trie[cur].nxt[i - 'a'];
        //op += i;
        //trie[cur].tmp = op;
    }
    trie[cur].ind.push_back(i);
}
void build(){
    queue < int > se;
    for(int j = 0; j < 26; j++){
        if(trie[0].nxt[j] != -1){
            trie[0].go[j] = trie[0].nxt[j];
            trie[trie[0].nxt[j]].link = 0;
            se.push(trie[0].nxt[j]);
        }
        else{
            trie[0].go[j] = 0;
        }
    }
    while(!se.empty()){
        int node = se.front();
        se.pop();
        for(int j = 0; j < 26; j++){
            int cur = trie[node].nxt[j];
            if(cur != -1){
                trie[node].go[j] = cur;
                trie[cur].link = trie[trie[node].link].go[j];
                if((int)trie[trie[cur].link].ind.size()){
                    trie[cur].Link = trie[cur].link;
                }
                else{
                    trie[cur].Link = trie[trie[cur].link].Link;
                }
                se.push(cur);
            }
            else{
                trie[node].go[j] = trie[trie[node].link].go[j];
            }
        }
    }
}
void solve(){
    trie.push_back(Node());
    string s;
    cin >> s;
    int q;
    cin >> q;
    for(int i = 1; i <= q; i++){
        string t;
        cin >> t;
        add(t, i);
    }
    build();
    int cur = 0;
    for(auto i: s){
        cur = trie[cur].go[i - 'a'];
        int Cur = cur;
        while(Cur){
            trie[Cur].cnt++;
            Cur = trie[Cur].Link;
        }
        //cout << trie[cur].tmp << "\n";
    }
    for(auto op: trie){
        for(int j: op.ind){
            ans[j] = op.cnt;
        }
    }
    for(int i = 1; i <= q; i++){
        cout << ans[i] << "\n";
    }
}
