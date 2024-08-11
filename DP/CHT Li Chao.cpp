//O(nlogn)
//works for dp[i] = min/max(const + dp[j] + b[j] * a[i]) or something like that and no further restrictions
struct Line{
    ll a, b;
    Line(){}
    Line(ll A, ll B){
        a = A, b = B;
    }
    ll val(ll x){
        return a * x + b;
    }
};
struct node{
    Line line;
    node *left, *right;
    node(){
        left = NULL, right = NULL;
        line = Line();
    }
    node(Line L){
        line = L;
        left = NULL, right = NULL;
    }
};
void update(int s, int e, node* &cur, Line line){
    if(cur == NULL){
        cur = new node(line);
        return;
    }
    bool Left = cur->line.val(s) > line.val(s);
    bool Middle = cur->line.val(md + 1) > line.val(md + 1);
    bool Right = cur->line.val(e) > line.val(e);
    if(Left == Right){
        if(Left){
            cur->line = line;
        }
    }
    else if(Middle == Right){
        if(Right){
            swap(line, cur->line);
        }
        update(s, md, cur->left, line);
    }
    else if(Left == Middle){
        if(Left){
            swap(line, cur->line);
        }
        update(md + 1, e, cur->right, line);
    }
    
}
ll query(int s, int e, node *cur, ll x){
    if(cur == NULL || e < x || s > x){
        return 1e18;
    }
    return min({cur->line.val(x), query(s, md, cur->left, x), query(md + 1, e, cur->right, x)});
}
int n;
ll dp[200005], s[200005], f[200005], x;
void solve(){ 
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> f[i];
    }
    node *root = NULL;
    Line emp = Line(x, 0);
    update(1, 1e6, root, emp);
    for(int i = 1; i <= n; i++){
        dp[i] = query(1, 1e6, root, s[i]);
        Line cur = Line(f[i], dp[i]);
        update(1, 1e6, root, cur);
    }
    cout << dp[n] << "\n";
}
