bool intersect(point a, point b, point c, point d){
    point ab = b - a, cd = d - c, ac = c - a, ad = d - a, bc = c - b, bd = d - b; 
    if(!CP(ab, cd)){
        if(!CP(ac, ad) && !CP(bc, bd) && !CP(ac, bc) && !CP(ad, bd)){
            if(max(a.x, b.x) < min(c.x, d.x) || max(a.y, b.y) < min(c.y, d.y)){
                return 0;
            }
            else if(min(a.x, b.x) > max(c.x, d.x) || min(a.y, b.y) > max(c.y, d.y)){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            return 1;
        }
    }
    else{
        if(Get(CP(ac, ad)) == Get(CP(bc, bd)) || Get(CP(ac, bc)) == Get(CP(ad, bd))){
            return 0;
        }
        else{
            return 1;
        }
    }
}
bool boundary(point a, point b, point c){
    point ab = b - a, ac = c - a;
    if(!CP(ab, ac)){
        if(min(b.x, c.x) <= a.x && a.x <= max(b.x, c.x) && min(b.y, c.y) <= a.y && a.y <= max(b.y, c.y)){
            return 1;
        }
    }
    return 0;
}
int n, m;
point a[100005];
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        a[i].read();
    }
    a[n + 1] = a[1];
    while(m--){
        point b;
        b.read();
        point c(b.x + 1, 1e9);
        bool Boundary = 0;
        ll cnt = 0;
        for(int i = 1; i <= n; i++){
            if(boundary(b, a[i], a[i + 1])){
                Boundary = 1;
                break;
            }
            cnt += intersect(b, c, a[i], a[i + 1]);
        }
        if(Boundary){
            cout << "BOUNDARY\n";
        }
        else if(cnt & 1){
            cout << "INSIDE\n";
        }
        else{
            cout << "OUTSIDE\n";
        }
    }
}
