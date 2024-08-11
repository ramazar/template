ll inv_mod(ll a, ll m) { 
    assert(0<a);
    assert(a<m);
    return a==1 ? 1 : m - m * inv_mod(m%a, a) / a;
}
