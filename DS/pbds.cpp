#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//find_by_order(k):returns a pointer on the k + 1th element
//order_of_key(k):returns the number of elements strictly smaller than k
//to turn it into ordered multiset , just change less < T > to less_equal < T >
