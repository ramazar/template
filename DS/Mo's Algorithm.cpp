inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
     if (pow == 0) {
        return 0;
     }
     int hpow = 1 << (pow-1);
     int seg = (x < hpow) ? (
      (y < hpow) ? 0 : 3
     ) : (
      (y < hpow) ? 1 : 2
     );
     seg = (seg + rotate) & 3;
     const int rotateDelta[4] = {3, 0, 0, 1};
     int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
     int nrot = (rotate + rotateDelta[seg]) & 3;
     int64_t subSquareSize = int64_t(1) << (2*pow - 2);
     int64_t ret = seg * subSquareSize;
     int64_t ad = gilbertOrder(nx, ny, pow-1, nrot);
     ret += (seg == 1 || seg == 2) ? ad : (subSquareSize - ad - 1);
     return ret;
}
struct node{
    ll l , r , i , op ;
    int64_t ord ;
    void compute(){
        ord = gilbertOrder(l, r, 20, 0) ;
    } 
}Q[200005];
//Mo on Tree:
//subtree queries normal Mo , nothing changes
//path queries on the other hand , have some changes:
//modified DFS order , increment the timer when going in AND out of a node
//let the query be (u , v) and In[u] <= In[v]
//case 1:Lca(u , v) = u , then query range is l = In[u] , r = In[v]
//case 2:Lca(u , v) != u , then l = Out[u] , r = In[v] , also including another range l’ = r’ = In[Lca(u , v)]
//when entering an index , if it is the first time visiting the node we increment , else we decrement

//Mo with Update:
int BLOCK;
struct query {
  int l, r, id, t;
  array<int, 3> P () {
    return {l / BLOCK, (l / BLOCK) & 1 ? -r / BLOCK : r / BLOCK, (r / BLOCK) & 1 ? -t : t};
  }
  bool operator< (query &q) {
    return P() < q.P();
  }
};
 
vector<int> a, ic;
int ffreq[(int)2e5], freq[(int)2e5], s = 1, e = 0, t = 0;
 
void add (int x, int v) {
  --ffreq[freq[x]];
  freq[x] += v;
  ++ffreq[freq[x]];
}
 
void chg (int i, int &v) {
  if (s <= i && i <= e) {
    add(v, 1);
    add(a[i], -1);
  }
  swap(a[i], v);
}
 
int main (){
 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  int n, q;
  cin >> n >> q;
  BLOCK = pow(n, 2./3);
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ic.push_back(a[i]);
  }
  vector<query> qs;
  vector<array<int, 2>> us;
  for (int i = 0; i < q; ++i) {
    int t, l, r;
    cin >> t >> l >> r, --l;
    if (t == 1) {
      qs.push_back({l, --r, (int)qs.size(), (int)us.size()});
    }
    else {
      us.push_back({l, r});
      ic.push_back(r);
    }
  }
  sort(qs.begin(), qs.end());
  sort(ic.begin(), ic.end());
  ic.resize(unique(ic.begin(), ic.end()) - ic.begin());
  for (auto &i : a) {
    i = lower_bound(ic.begin(), ic.end(), i) - ic.begin();
  }
  for (auto &i : us) {
    i[1] = lower_bound(ic.begin(), ic.end(), i[1]) - ic.begin();
  }
  q = qs.size();
  // the most important part...
  vector<int> ans(q);
  for (int i = 0; i < q; ++i) {
    while (t < qs[i].t) chg(us[t][0], us[t][1]), ++t;
    while (t > qs[i].t) --t, chg(us[t][0], us[t][1]);
    while (e < qs[i].r) add(a[++e], 1);
    while (s > qs[i].l) add(a[--s], 1);
    while (s < qs[i].l) add(a[s++], -1);
    while (e > qs[i].r) add(a[e--], -1);
    for (int j = 0; ; ++j) {
      if (!ffreq[j]) {
        ans[qs[i].id] = j;
        break;
      }
    }
  }
  for (auto i : ans) {
    cout << i << "\n";
  }
