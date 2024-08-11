typedef long long ll;
typedef long double ld;
typedef complex<long double> base;
const double PI = acosl(-1.0);
const base ii = base(0, 1);
int cur_base = 1;
vector < base > roots = {base(0, 0), base(1, 0)};
void fft (vector<base> & a, bool invert) {
    int n = (int) a.size();
    if (invert) {
        for (auto& it : a) {
            it = conj(it);
        }
    }
    if ((1 << cur_base) < n) {
        roots.resize(n);
        while ((1 << cur_base) < n) {
            ld ang = (2 * PI) / (1 << (cur_base + 1));
            for (int i = (1 << (cur_base - 1)); i < (1 << cur_base); i++) {
                roots[i << 1] = roots[i];
                ld ang_i = ang * (2 * i + 1 - (1 << cur_base));
                roots[(i << 1) + 1] = base(cosl(ang_i), sinl(ang_i));
            }
            cur_base++;
        }
    }
    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }
    for (int len=2; len<=n; len<<=1) {
        for (int i=0; i<n; i+=len) {
            for (int j=0; j<len/2; ++j) {
                base u = a[i+j],  v = a[i+j+len/2] * roots[j + len / 2];
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
            }
        }
    }
    if (invert)
        for (int i=0; i<n; ++i)
            a[i] /= n;
}
vector < ll > poly_mult(vector < ll >& a, vector < ll >& b) {
    if (a.empty() || b.empty()) return {};
    int s = a.size() + b.size() - 1;
    int sz = 1;
    while (sz < s) sz <<= 1;
    vector < base > ff(sz);
    for (int i = 0; i < sz; i++) {
        ld x = (i < a.size() ? a[i] : 0);
        ld y = (i < b.size() ? b[i] : 0);
        ff[i] = base(x, y);
    }
    fft(ff, false);
    vector < base > x(sz);
    for (int i = 0; i < sz; i++) {
        int j = (sz - i) & (sz - 1);
        x[i] = (ld)0.25 * ii * (conj(ff[j] * ff[j]) - ff[i] * ff[i]);
    }
    fft(x, true);
    vector < ll > ans(a.size() + b.size() - 1);
    for (int i = 0; i < ans.size(); i++) {
        ans[i] = llround(x[i].real());
    }
    return ans;
}
