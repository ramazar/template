//O(knlogn)
//works for dp[i][j] = min/max(dp[i – 1][k] + cost(k + 1 , j)); and A[i][j] <= A[i][j + 1]
//A[i][j] is the smallest k such that k is optimal
ll dp[3005][3005], a[3005];
ll Cost(int l, int r){
    return (a[r] - a[l - 1]) * (a[r] - a[l - 1]);
}
void mem(int l, int r, int j, int optl, int optr){
    if(l > r){
        return;
    }
    ll &ret = dp[j][mid] = 1e17, opt = 1e17;
    for(int i = optl; i <= min(mid, optr); i++){
        if(dp[j - 1][i] + Cost(i + 1, mid) < ret){
            ret = dp[j - 1][i] + Cost(i + 1, mid);
            opt = i;
        }
    }
    mem(l, mid - 1, j, optl, opt);
    mem(mid + 1, r, j, opt, optr);
}
int n, k;
void solve(){ 
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i - 1];
        dp[0][i] = 1e17;
    }
    for(ll j = 1; j <= k; j++){
        mem(1, n, j, 0, n);
    }
    cout << dp[k][n] << "\n";
}
