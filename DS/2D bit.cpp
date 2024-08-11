int tree[1005][1005], n, q;
void update(int x, int y, ll val){
    while(x <= n){
        int _y = y;
        while(_y <= n){
            tree[x][_y] += val;
            _y += _y & -_y;
        }
        x += x & -x;
    }
}
ll query(int x, int y){
    ll ret = 0;
    while(x > 0){
        int _y = y;
        while(_y > 0){
            ret += tree[x][_y];
            _y -= _y & -_y;
        }
        x -= x & -x;
    }
    return ret;
}
int a[1005][1005];
void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char c;
            cin >> c;
            a[i][j] = c == '*';
            update(i, j, a[i][j]);
        }
    }
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int i, j;
            cin >> i >> j;
            update(i, j, -a[i][j]);
            a[i][j] ^= 1;
            update(i, j, a[i][j]);
        }
        else{
            int i1, j1, i2, j2;
            cin >> i1 >> j1 >> i2 >> j2;
            cout << query(i2, j2) - query(i2, j1 - 1) - query(i1 - 1, j2) + query(i1 - 1, j1 - 1) << "\n";
        }
    }
}
