struct circle{
    point a;
    int r;
    void read(){
        a.read();
        cin >> r;
    }
    long double sector(long double ang){
        return (long double)r * r * 0.5 * (ang - sin(ang));
    }
};
long double dis(point a, point b){
    return sqrtl((a - b) * (a - b));
}
long double ang(long double a, long double b, long double c){
    return acos((a * a + b * b - c * c) / (2 * a * b));
}
long double area(circle a, circle b){
    long double ds = dis(a.a, b.a);
    if(ds > a.r + b.r)return 0;
    if(ds + a.r <= b.r){
        return Pi * a.r * a.r;
    }
    if(ds + b.r <= a.r){
        return Pi * b.r * b.r;
    }
    long double angA = 2 * ang(ds, a.r, b.r);
    long double angB = 2 * ang(ds, b.r, a.r);
    return a.sector(angA) + b.sector(angB);
}
