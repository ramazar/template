struct point{
    ll x, y;
    point(ll xx, ll yy){
        x = xx, y = yy;
    }
    point(){}
    void read(){
        cin >> x >> y;
    }
    point operator - (const point B)const{
        point A = *this;
        point ret;
        ret.x = A.x - B.x, ret.y = A.y - B.y;
        return ret;
    }
    bool operator < (const point other)const{
        return make_pair(x, y) < make_pair(other.x, other.y);
    }
};
ll CP(point a, point b){
    return a.x * b.y - a.y * b.x;
}
ll Get(ll cp){
    return (!cp ? 0 : (cp < 0 ? 1 : 2));
}
ll Dis(point a, point b){
    point c = b - a;
    return c.x * c.x + c.y * c.y;
}
bool cmp(const point &a, const point &b){
    return a.y < b.y;
}
int n;
point a[200005];
ll bt(int l, int r){
    if(l == r)return 4e18;
    if(l == r - 1)return Dis(a[l], a[r]);
    ll d = min(bt(l, mid), bt(mid + 1, r));
    vector < point > cur;
    for(int i = l; i <= r; i++){
        ll tmp = abs(a[i].x - a[mid].x);
        tmp *= tmp;
        if(tmp <= d)cur.push_back(a[i]);
    }
    sort(all(cur), cmp);
    for(int i = 0; i < cur.size(); i++){
        for(int j = i + 1; j < cur.size(); j++){
            ll tmp = cur[j].y - cur[i].y;
            tmp *= tmp;
            if(tmp >= d)break;
            d = min(d, Dis(cur[i], cur[j]));
        }
    }
    return d;
}
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        a[i].read();
    }
    sort(a + 1, a + n + 1);
    cout << bt(1, n) << "\n";
}
