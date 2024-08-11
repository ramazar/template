int n, dep[200005], in[200005], out[200005], lg[400005], k;
pair < int, int > dp[19][400005];
vector < int > adj[100005];
void dfs(int v, int par){
    dep[v] = dep[par] + 1;
    dp[0][++k] = {dep[v], v};
    in[v] = k;
    for(auto u: adj[v]){
        if(u == par)continue;
        dfs(u, v);
        dp[0][++k] = {dep[v], v};
    }
}
void build(){
    for(int i = 2; i <= 2 * n; i++){
        lg[i] = lg[i / 2] + 1;
    }
    for(int j = 1; j < 19; j++){
        for(int i = 1; i + (1 << j) - 1 <= k; i++){
            dp[j][i] = min(dp[j - 1][i], dp[j - 1][i + (1 << (j - 1))]);
        }
    }
}
pair < int, int > mn(int l, int r){
    int Lg = lg[r - l + 1];
    return min(dp[Lg][l], dp[Lg][r - (1 << Lg) + 1]);
}
int Lca(int u, int v){
    int l = min(in[u], in[v]), r = max(in[u], in[v]);
    return mn(l, r).S;
}
int dis(int i, int j){
    return dep[i] + dep[j] - 2 * dep[Lca(i, j)];
}
int siz[100005], vis[100005];
void build(int v, int par){
    siz[v] = 1;
    for(auto u: adj[v]){
        if(vis[u] || u == par)continue;
        build(u, v);
        siz[v] += siz[u];
    }
}
int get(int v, int par, int cnt){
    for(auto u: adj[v]){
        if(cnt > siz[u] || u == par || vis[u])continue;
        return get(u, v, cnt);
    }
    return v;
}
int pr[100005], ans[100005];
int dfs(int v){
    build(v, 0);
    int cen = get(v, 0, siz[v] / 2);
    vis[cen] = 1;
    for(auto u: adj[cen]){
        if(vis[u])continue;
        pr[dfs(u)] = cen;
    }
    return cen;
}
void update(int v){
    int u = v;
    while(u){
        ans[u] = min(ans[u], dis(u, v));
        u = pr[u];
    }
}
int query(int v){
    int u = v, ret = ans[v];
    while(u){
        ret = min(ret, ans[u] + dis(u, v));
        u = pr[u];
    }
    return ret;
}
int m;
void solve(){
    cin >> n >> m;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    dfs(1, 0);
    build();
    dfs(1);
    for(int i = 2; i <= n; i++){
        ans[i] = dis(1, i);
    }
    while(m--){
        int type, v;
        cin >> type >> v;
        if(type == 1){
            update(v);
        }
        else{
            cout << query(v) << "\n";
        }
    }
    
}
