vector < int > adj[500005];
int tree[500005], Par[500005], Nxt[500005], Sz[500005], Dep[500005], Chain[500005], Num[500005], Csz[500005], Top[500005], Mx[500005];
void dfs(int v, int par){
    Par[v] = par;
    Sz[v] = 1;
    Nxt[v] = 0;
    for(auto u: adj[v]){
        if(u == par)continue;
        Dep[u] = Dep[v] + 1;
        dfs(u, v);
        if(Sz[u] > Sz[Nxt[v]])Nxt[v] = u;
        Sz[v] += Sz[u];
    }
}
int cnt = 1, all = 0, n;
void build(){
    for(int i = n - 1; i > 0; i--){
        tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
    }
}
void update(int i, int val){
    i += n - 1;
    tree[i] = val;
    for(; i > 1; i /= 2){
        tree[i / 2] = max(tree[i], tree[i ^ 1]);
    }
}
int query(int l, int r){
    int ret = 0;
    for(l += n - 1, r += n - 1; l < r; l /= 2, r /= 2){
        if(l & 1)ret = max(ret, tree[l++]);
        if(r & 1)ret = max(ret, tree[--r]);
    }
    return ret;
}
int q, a[500005];
void hld(int v, int par){
    Chain[v] = cnt;
    Num[v] = ++all;
    Mx[cnt] = max(Mx[cnt], a[v]);
    update(all, a[v]);
    if(!Csz[cnt])Top[cnt] = v;
    Csz[cnt]++;
    if(Nxt[v])hld(Nxt[v], v);
    for(auto u: adj[v]){
        if(u == par || u == Nxt[v])continue;
        cnt++;
        hld(u, v);
    }
}
int Go(int u, int v){
    int Ans = 0;
    while(Chain[u] != Chain[v]){
        if(Dep[Top[Chain[u]]] < Dep[Top[Chain[v]]])swap(u, v);
        int Start = Top[Chain[u]];
        if(Num[u] == Num[Start] + Csz[Chain[u]] - 1)Ans = max(Ans, Mx[Chain[u]]);
        else Ans = max(Ans, query(Num[Start], Num[u] + 1));
        u = Par[Start];
    }
    if(Dep[u] > Dep[v])swap(u, v);
    Ans = max(Ans, query(Num[u], Num[v] + 1));
    return Ans;
}
void modify(int i, int val){
    update(Num[i], val);
    int l = Num[Top[Chain[i]]], r = l + Csz[Chain[i]];
    Mx[Chain[i]] = query(l, r);
}
void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    while(n & (n - 1))n++;
    dfs(1, 1);
    hld(1, 0);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int i, val;
            cin >> i >> val;
            modify(i, val);
        }
        else{
            int u, v;
            cin >> u >> v;
            cout << Go(u, v) << " ";
        }
    }
}
