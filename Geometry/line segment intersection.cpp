struct point{
    ll x, y;
    point(ll xx, ll yy){
        x = xx, y = yy;
    }
    point(){}
    void read(){
        cin >> x >> y;
    }
    point operator -(point B){
        point A = *this;
        point ret;
        ret.x = A.x - B.x, ret.y = A.y - B.y;
        return ret;
    }
};
ll CP(point a, point b){
    return a.x * b.y - a.y * b.x;
}
ll Get(ll cp){
    return (!cp ? 0 : (cp < 0 ? 1 : 2));
}
void solve(){
    point a, b, c, d;
    a.read(), b.read(), c.read(), d.read();
    point ab = b - a, cd = d - c, ac = c - a, ad = d - a, bc = c - b, bd = d - b; 
    if(!CP(ab, cd)){
        if(!CP(ac, ad) && !CP(bc, bd) && !CP(ac, bc) && !CP(ad, bd)){
            if(max(a.x, b.x) < min(c.x, d.x) || max(a.y, b.y) < min(c.y, d.y)){
                cout << "NO\n";
            }
            else if(min(a.x, b.x) > max(c.x, d.x) || min(a.y, b.y) > max(c.y, d.y)){
                cout << "NO\n";
            }z
            else{
                cout << "YES\n";
            }
        }
        else{
            cout << "NO\n";
        }
    }
    else{
        if(Get(CP(ac, ad)) == Get(CP(bc, bd)) || Get(CP(ac, bc)) == Get(CP(ad, bd))){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
}
