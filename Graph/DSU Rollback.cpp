int par[100005], len[100005];
int getpar(int x){
    return (par[x] < 0 ? x : getpar(par[x]));
}
int getlen(int x){
    return (par[x] < 0 ? 0 : getlen(par[x]) ^ len[x]);
}
vector < tuple < int, int, int > > se;
bool mrg(int u, int v){
    int U = getlen(u), V = getlen(v);
    u = getpar(u), v = getpar(v);
    if(u == v){
        return U != V;
    }
    if(par[u] > par[v])swap(u, v);
    se.push_back({u, par[u], len[u]});
    se.push_back({v, par[v], len[v]});
    par[u] += par[v];
    par[v] = u;
    len[v] = U ^ V ^ 1;
    return true;
}
void persist(){
    se.push_back({-1, 0, 0});
}
void goback(){
    while(!se.empty()){
        auto [u, p, l] = se.back();
        se.pop_back();
        if(u == -1)break;
        par[u] = p, len[u] = l;
    }
}
void go(int s, int e, vector < tuple < int, int, int, int > > &se, bool ans){
    persist();
    if(s == e){
        for(auto [l, r, u, v]: se){
            ans &= mrg(u, v);
        }
        cout << (ans ? "YES\n" : "NO\n");
        goback();
        return;
    }
    vector < tuple < int, int, int, int > > seL, seR;
    for(auto [l, r, u, v]: se){
        if(l <= s && e <= r){
            ans &= mrg(u, v);
        }
        else{
            if(md >= l)seL.push_back({l, r, u, v});
            if(md + 1 <= r)seR.push_back({l, r, u, v});
        }
    }
    go(s, md, seL, ans);
    go(md + 1, e, seR, ans);
    goback();
}
void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        par[i] = -1;
    }
    map < pair < int, int >, int > mp;
    vector < tuple < int, int, int, int > > se;
    for(int i = 1; i <= q; i++){
        int u, v;
        cin >> u >> v;
        if(mp.count({u, v})){
            se.push_back({mp[{u, v}], i - 1, u, v});
            mp.erase({u, v});
        }
        else{
            mp[{u, v}] = i;
        }
    }
    for(auto [u, j]: mp){
        se.push_back({j, q, u.F, u.S});
    }
    go(1, q, se, 1);
}
