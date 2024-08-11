const ll mod = 998244353;
const ll root = 15311432; // which is basically 3 ^ 119
const ll root_1 = 469870224;
const ll root_pw = (1 << 23);
/**
const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1 << 20;
const int mod = 7340033;
**/
void fft(vector<ll> & a, bool invert) {
    int n = a.size();
 
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
 
        if (i < j)
            swap(a[i], a[j]);
    }
 
    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);
 
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }
 
    if (invert) {
        int n_1 = inverse(n, mod);
        for (ll & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}
vector<ll> mul(vector<ll> const& a, vector<ll> const& b){
 
    vector<ll> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while(n < (int)a.size() + (int)b.size()){
        n <<= 1;
    }
    fa.resize(n);
    fb.resize(n);
 
    fft(fa, false);
    fft(fb, false);
    for(int i = 0; i < n; ++i){
        fa[i] = fa[i] * fb[i] % mod;
    }
    fft(fa, true);
    while(fa.size() > 1 && fa[fa.size() - 1] == 0){
        fa.pop_back();
    }
 
    return fa;
}
