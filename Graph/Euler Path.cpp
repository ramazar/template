//gives a path that goes through every edge exactly once
void dfs(ll v){
    while(!adj[v].empty()){
        pll op = adj[v].back() ;
        adj[v].pop_back() ;
        dfs(op.F) ;
    }
    ans.pb(v) ;
}
void solve(){
    cin >> n >> m ;
    for(ll i = 1 ; i <= m ; i++){
        cin >> o >> p ;
        adj[o].pb({p , i}) ;
        a[o]++ , b[p]++ ;
    }
    ll cnt = 0 ;
    for(ll i = 1 ; i <= n ; i++){
        if(i == 1 && a[i] != b[i] + 1)R void(cout << "IMPOSSIBLE" << endl) ;
        if(i == n && a[i] != b[i] - 1)R void(cout << "IMPOSSIBLE" << endl) ;
        if(a[i] == b[i] + 1 && i > 1)R void(cout << "IMPOSSIBLE" << endl) ;
        if(a[i] == b[i] - 1 && i < n)R void(cout << "IMPOSSIBLE" << endl) ;
        if(a[i] == b[i])cnt++ ;
    }
    if(cnt != n - 2)R void(cout << "IMPOSSIBLE" << endl) ;
    dfs(1) ;
    reverse(all(ans)) ;
    if(sz(ans) != m + 1)R void(cout << "IMPOSSIBLE" << endl) ;
    for(auto u : ans)cout << u << " " ;
}
