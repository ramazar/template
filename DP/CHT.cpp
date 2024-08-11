//O(n)
//same as O(nlogn) but has to be b[k] >= b[k + 1] and a[k] <= a[k + 1]
struct line{
    int m = 0;
    ll b = 1e17;
    line(){}
    line(ll M, ll B){
        m = M, b = B;
    }
    ll val(ll x){
        return m * x + b;
    }
};
int n, cur = 0;
ll x, s[200005], f[200005], dp[200005];
vector < line > se;
void Add(int m, ll b){
    line op(m, b);
    while(se.size() > 1 && (se.end()[-1].b - se.end()[-2].b) * (se.end()[-1].m - op.m) >= (op.b - se.end()[-1].b) * (se.end()[-2].m - se.end()[-1].m)){
        se.pop_back();
    }
    se.push_back(op);
}
ll Get(ll x){
    cur = min(cur, (int)se.size() - 1);
    while(cur + 1 < se.size() && se[cur + 1].val(x) <= se[cur].val(x)){
        cur++;
    }
    return se[cur].val(x);
}
void solve(){
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> f[i];
    }
    se.clear(), cur = 0;
    Add(x, 0);
    for(int i = 1; i <= n; i++){
        dp[i] = Get(s[i]);
        Add(f[i], dp[i]);
    }
    cout << dp[n] << "\n";
}
