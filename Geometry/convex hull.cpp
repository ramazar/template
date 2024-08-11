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
int n;
point a[200005];
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        a[i].read();
    }
    vector < point > ans, hull;
    sort(a + 1, a + n + 1);
    for(int j = 0; j < 2; j++){
        for(int i = 1; i <= n; i++){
            while(hull.size() >= 2){
                point lst1 = hull.back();
                hull.pop_back();
                point lst2 = hull.back();
                if(Get(CP(lst1 - lst2, a[i] - lst2)) != 2){
                    hull.push_back(lst1);
                    break;
                }
            }
            hull.push_back(a[i]);
        }
        hull.pop_back();
        while(!hull.empty()){
            ans.push_back(hull.back());
            hull.pop_back();
        }
        reverse(a + 1, a + n + 1);
    }
    cout << ans.size() << "\n";
    for(auto u: ans){
        cout << u.x << " " << u.y << "\n";
    }
}
