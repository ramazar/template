// returns nCr modulo mod where mod is a prime
// Complexity: log(n)
mint lucas(ll n, ll r) {
  if (r > n) return 0;
  if (n < mod) return C.ncr(n, r);
  return lucas(n / mod, r / mod) * lucas(n % mod, r % mod);
}
