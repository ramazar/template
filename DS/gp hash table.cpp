//put this after include bits
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
//put this wherever you like
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
gp_hash_table<int, ll, chash> dp[100005];
