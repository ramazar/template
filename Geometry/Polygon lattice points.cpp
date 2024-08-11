int n;
point a[100005];
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        a[i].read();
    }
    a[n + 1] = a[1];
    ll In = 0, Boundary = n;
    for(int i = 2; i < n; i++){
        In += CP(a[i] - a[1], a[i + 1] - a[1]);
    }
    for(int i = 1; i <= n; i++){
        point tmp = a[i + 1] - a[i];
        tmp.x = abs(tmp.x), tmp.y = abs(tmp.y);
        Boundary += __gcd(tmp.x, tmp.y) - 1;
    }
    In = (abs(In) - Boundary + 2) / 2;
    cout << In << " " << Boundary << "\n";
}
