int n, m, ans[100005];
bool vis[100005];
vector < int > adj[100005], adjR[100005], order, comp;
void dfs(int v){
    vis[v] = 1;
    for(auto u: adj[v]){
        if(!vis[u]){
            dfs(u);
        }
    }
    order.push_back(v);
}
void dfsR(int v){
    vis[v] = 1;
    for(auto u: adjR[v]){
        if(!vis[u]){
            dfsR(u);
        }
    }
    comp.push_back(v);
}
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adjR[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    reverse(all(order));
    for(int i = 1; i <= n; i++){
        vis[i] = 0;
    }
    int cnt = 0;
    for(auto i: order){
        if(!vis[i]){
            comp.clear();
            dfsR(i);
            cnt++;
            for(auto u: comp){
                ans[u] = cnt;
            }
        }
    }
    cout << cnt << "\n";
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
}
