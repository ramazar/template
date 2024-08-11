//O(n * n)
//works for dp[i][j] = min/max(dp[i][k] + dp[k][j]) + c[i][j] amd A[i][j - 1] <= A[i][j] <= A[i][j + 1]
//A[i][j] is the smallest k such that k is optimal
int n, opt[5005][5005];
ll dp[5005][5005], a[5005];
ll Cost(ll l, ll r){
    return a[r] - a[l - 1];
}
void solve(){ 
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        opt[i][i] = i;
        a[i] += a[i - 1];
    }
    for(int i = n - 1; i >= 1; i--){
        for(int j = i + 1; j <= n; j++){
            ll &ret = dp[i][j] = 1e17;
            for(int k = opt[i][j - 1]; k <= min(j - 1, opt[i + 1][j]); k++){
                if(ret >= dp[i][k] + dp[k + 1][j] + Cost(i, j)){
                    ret = dp[i][k] + dp[k + 1][j] + Cost(i, j);
                    opt[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][n] << "\n";
}
