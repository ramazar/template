int n;
point a[100005];
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        a[i].read();
    }
    ll ans = 0;
    for(int i = 2; i < n; i++){
        ans += CP(a[i] - a[1], a[i + 1] - a[1]);
    }
    cout << abs(ans) << "\n";
}
