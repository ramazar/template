typedef complex < long double > cd; 
const long double PI = acos(-1);
vector < cd > a((1 << 19)) , b((1 << 19)) ;
void fft(vector<cd> &a, bool inv){
    int N = (int) a.size();
    for(int i = 1, j = 0; i < N; i++){  
        int bit = N>>1;
        for(; j&bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
 
        if(i < j)
            swap(a[i], a[j]);
    }
    for(int len = 2; len <= N; len <<= 1){
        long double theta = 2*PI / len * (inv ? -1 : 1);
        cd wlen(cos(theta), sin(theta));
        for(int i = 0; i < N; i += len){
            cd w(1);
            for(int j = 0; j < len / 2; j++){
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if(inv)
        for(cd &z : a)
            z /= N;
} 
void solve(){
    cin >> k >> n >> m ; 
    for(ll i = 1 ; i <= n ; i++){
        cin >> o ;
        a[o] += 1; 
    }
    for(ll i = 1 ; i <= m ; i++){
        cin >> o ; 
        b[o] += 1; 
    }
    fft(a , 0) ; 
    fft(b , 0) ;
    for(ll i = 0 ; i < (1 << 19) ; i++)a[i] *= b[i] ; 
    fft(a , 1) ; 
    for(ll i = 2 ; i <= 2 * k ; i++){
        cout << (ll)round(a[i].real()) << " " ;
    } 
}
