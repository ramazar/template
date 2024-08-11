int k, Left[30 * 300005], Right[30 * 300005], ver[300005], a[300005];
int Lazy[30 * 300005], Val[30 * 300005];
int newParent(int l, int r){
    k++;
    Left[k] = l, Right[k] = r;
    Val[k] = Val[l] + Val[r];
    return k;
}
int newLeaf(int val){
    k++;
    Left[k] = Right[k] = 0;
    Val[k] = val;
    return k;
}
int newLazy(int s, int e, int node, int val){
    k++;
    Left[k] = Left[node], Right[k] = Right[node];
    Lazy[k] = Lazy[node] + val;
    Val[k] = Val[node] + (e - s + 1) * val;
    return k;
}
void lz(int s, int e, int node){
    if(Lazy[node]){
        if(s != e){
            Left[node] = newLazy(s, md, Left[node], Lazy[node]);
            Right[node] = newLazy(md + 1, e, Right[node], Lazy[node]);
        }
        Lazy[node] = 0;
    }
}
int build(int s, int e){
    if(s == e){
        return newLeaf(a[s]);
    }
    return newParent(build(s, md), build(md + 1, e));
}
int update(int s, int e, int node, int i, int val){
    if(s > i || e < i)return node;
    if(s == e)return newLeaf(val);
    lz(s, e, node);
    return newParent(update(s, md, Left[node], i, val), update(md + 1, e, Right[node], i, val));
}
int update(int s, int e, int node, int l, int r, int val){
    if(s > r || e < l)return node;
    if(l <= s && e <= r)return newLazy(s, e, node, val);
    lz(s, e, node);
    return newParent(update(s, md, Left[node], l, r, val), update(md + 1, e, Right[node], l, r, val));
}
int query(int s, int e, int node, int l, int r){
    if(s > r || e < l)return 0;
    if(l <= s && e <= r)return Val[node];
    lz(s, e, node);
    return query(s, md, Left[node], l, r) + query(md + 1, e, Right[node], l, r);
}
int n, m;
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ver[0] = build(1, n);
    int cur = 0;
    while(m--){
        char c;
        cin >> c;
        if(c == 'C'){
            int l, r, val;
            cin >> l >> r >> val;
            ver[++cur] = update(1, n, ver[cur], l, r, val);
        }
        else if(c == 'Q'){
            int l, r;
            cin >> l >> r;
            cout << query(1, n, ver[cur], l, r) << "\n";
        }
        else if(c == 'H'){
            int l, r, t;
            cin >> l >> r >> t;
            cout << query(1, n, ver[t], l, r) << "\n";
        }
        else{
            int t;
            cin >> t;
            cur = t;
        }
    }
}
