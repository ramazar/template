const int mod[] = {(ll)1e9 + 123, (ll)1e9 + 321}, p[] = {29, 31};
string t;
int pwr[2][200005];
pair < int, int > tree[2][4 * 200005];
pair < int, int > mrg(pair < int, int > a, pair < int, int > b, int len){
    return {((ll)a.F * pwr[0][len] + b.F) % mod[0], ((ll)a.S * pwr[1][len] + b.S) % mod[1]};
}
void build(int s, int e, int node, int i){
    if(s == e){
        tree[i][node].F = t[s] - 'a' + 1;
        tree[i][node].S = t[s] - 'a' + 1;
        return;
    }
    build(s, md, lx, i), build(md + 1, e, rx, i);
    tree[i][node] = mrg(tree[i][lx], tree[i][rx], e - md);
}
void update(int s, int e, int node, int id, int val, int i){
    if(s > id || e < id)return;
    if(s == e){
        tree[i][node] = {val, val};
        return;
    }
    update(s, md, lx, id, val, i), update(md + 1, e, rx, id, val, i);
    tree[i][node] = mrg(tree[i][lx], tree[i][rx], e - md);
}
pair < pair < int, int > , int > query(int s, int e, int node, int l, int r, int i){
    if(s > r || e < l)return {{0, 0}, 0};
    if(l <= s && e <= r)return {tree[i][node], e - s + 1};
    auto o1 = query(s, md, lx, l, r, i), o2 = query(md + 1, e, rx, l, r, i);
    pair < pair < int, int > , int > ret;
    ret.F = mrg(o1.F, o2.F, o2.S);
    ret.S = o1.S + o2.S;
    return ret;

}
