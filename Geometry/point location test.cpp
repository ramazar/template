void solve(){
    point a, b, c;
    a.read(), b.read(), c.read();
    point ab = a - b, ac = a - c;
    ll val = CP(ab, ac);
    if(!val){
        cout << "TOUCH\n";
    }
    else if(val > 0){
        cout << "LEFT\n";
    }
    else{
        cout << "RIGHT\n";
    }
}
