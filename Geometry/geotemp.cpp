//Billions of bilious blue blistering barnacles in a thundering typhoon!
//Yesterday is history, tomorrow is a mystery, today is a gift of God, which is why we call it the present.
#include<bits/stdc++.h>
#define F first 
#define S second
#define lx node * 2
//#define rx node * 2 + 1
#define md ((s + e) / 2)
#define mid ((l + r) / 2)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
struct point{
    int x, y;
    void read(){
        cin >> x >> y;
    }
    void print(){
        cout << "x = " << x << " " << "y = " << y << "\n";
    }
    const point operator + (const point &a) const {
        point ret;
        ret.x = x + a.x, ret.y = y + a.y;
        return ret;
    }
    const point operator - (const point &a) const {
        point ret;
        ret.x = x - a.x, ret.y = y - a.y;
        return ret;
    }
    const bool operator < (const point &a) const {
        return (x == a.x ? y < a.y : x < a.x);
    }
    const bool operator > (const point &a) const {
        return (x == a.x ? y > a.y : x > a.x);
    }
    const bool operator <= (const point &a) const {
        return (x == a.x ? y <= a.y : x < a.x);
    }
    const bool operator >= (const point &a) const {
        return (x == a.x ? y >= a.y : x > a.x);
    }
    const bool operator == (const point &a) const {
        return (x == a.x && y == a.y);
    }
    const bool operator != (const point &a) const {
        return (x != a.x || y != a.y);
    }
    const ll operator * (const point &a) const {
        return (ll)x * a.x + (ll)y * a.y;
    }
    const ll operator ^ (const point &a) const {
        return (ll)x * a.y - (ll)y * a.x;
    }
    const point operator * (const double factor) const{
        point ret;
        ret.x = factor * x, ret.y = factor * y;
        return ret;
    }
    const point operator / (const double factor) const{
        point ret;
        ret.x = x / factor, ret.y = y / factor;
        return ret;
    }
};
ll area(point a, point b, point c){
    return abs((a - b) ^ (a - c));
}
double dis(point a, point b){
    return sqrtl((a - b) * (a - b));
}
bool in(point a, point b, point c, point d){
    return (area(a, b, d) + area(a, c, d) + area(b, c, d) == area(a, b, c));
}
void solve(){
    
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0); 
    int t = 1; 
    //cin >> t; 
    while(t--){
        solve(); 
    }
}
