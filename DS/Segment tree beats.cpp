struct Node{
    ll mx1, mx2, cntmx, mn1, mn2, cntmn, sum, lazy;
    Node(){
        cntmx = cntmn = sum = 0;
        lazy = 0;
        mx1 = mx2 = -2e18;
        mn1 = mn2 = 2e18;
    }
    Node(ll v){
        sum = mx1 = mn1 = v;
        mx2 = -2e18, mn2 = 2e18;
        cntmx = cntmn = 1;
        lazy = 0;
    }
}tree[4 * 200005];
Node mrg(const Node a, const Node b){
    Node ret;
    //sum
    ret.sum = a.sum + b.sum;
    //mx
    if(a.mx1 == b.mx1){
        ret.mx1 = a.mx1;
        ret.mx2 = max(a.mx2, b.mx2);
        ret.cntmx = a.cntmx + b.cntmx;
    }
    else if(a.mx1 > b.mx1){
        ret.mx1 = a.mx1;
        ret.mx2 = max(a.mx2, b.mx1);
        ret.cntmx = a.cntmx;
    }
    else{
        ret.mx1 = b.mx1;
        ret.mx2 = max(a.mx1, b.mx2);
        ret.cntmx = b.cntmx;
    }
    //mn
    if(a.mn1 == b.mn1){
        ret.mn1 = a.mn1;
        ret.mn2 = min(a.mn2, b.mn2);
        ret.cntmn = a.cntmn + b.cntmn;
    }
    else if(a.mn1 < b.mn1){
        ret.mn1 = a.mn1;
        ret.mn2 = min(a.mn2, b.mn1);
        ret.cntmn = a.cntmn;
    }
    else{
        ret.mn1 = b.mn1;
        ret.mn2 = min(a.mn1, b.mn2);
        ret.cntmn = b.cntmn;
    }
    return ret;
}
ll a[200005];
int n, q;
void build(int s, int e, int node){
    if(s == e){
        tree[node] = Node(a[s]);
        return;
    }
    build(s, md, lx), build(md + 1, e, rx);
    tree[node] = mrg(tree[lx], tree[rx]);
}
void lz_sum(int s, int e, int node, ll val){
    tree[node].sum += val * (e - s + 1), tree[node].mx1 += val, tree[node].mn1 += val;
    if(tree[node].mn2 != 2e18)tree[node].mn2 += val;
    if(tree[node].mx2 != -2e18)tree[node].mx2 += val;
    tree[node].lazy += val;
}
void lz_mn(int s, int e, int node, ll val){
    if(val >= tree[node].mx1)return;
    tree[node].sum -= tree[node].mx1 * tree[node].cntmx;
    tree[node].mx1 = val;
    tree[node].sum += tree[node].mx1 * tree[node].cntmx;
    if(tree[node].cntmx == e - s + 1){
        tree[node].mn1 = val;
    }
    else if(tree[node].mn2 > val){
        tree[node].mn2 = val;
    }
}
void lz_mx(int s, int e, int node, ll val){
    if(val <= tree[node].mn1)return;
    tree[node].sum -= tree[node].mn1 * tree[node].cntmn;
    tree[node].mn1 = val;
    tree[node].sum += tree[node].mn1 * tree[node].cntmn;
    if(tree[node].cntmn == e - s + 1){
        tree[node].mx1 = val;
    }
    else if(tree[node].mx2 < val){
        tree[node].mx2 = val;
    }
}
void lz(int s, int e, int node){
    if(s == e)return;
    lz_sum(s, md, lx, tree[node].lazy);
    lz_sum(md + 1, e, rx, tree[node].lazy);
    tree[node].lazy = 0;
    lz_mn(s, md, lx, tree[node].mx1);
    lz_mn(md + 1, e, rx, tree[node].mx1);
    lz_mx(s, md, lx, tree[node].mn1);
    lz_mx(md + 1, e, rx, tree[node].mn1);
}
void updatemn(int s, int e, int node, int l, int r, ll val){
    if(s > r || e < l || val >= tree[node].mx1)return;
    if(l <= s && e <= r && tree[node].mx2 < val){
        lz_mn(s, e, node, val);
        return;
    } 
    lz(s, e, node);
    updatemn(s, md, lx, l, r, val), updatemn(md + 1, e, rx, l, r, val);
    tree[node] = mrg(tree[lx], tree[rx]);
}
void updatemx(int s, int e, int node, int l, int r, ll val){
    if(s > r || e < l || val <= tree[node].mn1)return;
    if(l <= s && e <= r && tree[node].mn2 > val){
        lz_mx(s, e, node, val);
        return;
    } 
    lz(s, e, node);
    updatemx(s, md, lx, l, r, val), updatemx(md + 1, e, rx, l, r, val);
    tree[node] = mrg(tree[lx], tree[rx]);
}
void updatesum(int s, int e, int node, int l, int r, ll val){
    if(s > r || e < l)return;
    if(l <= s && e <= r){
        lz_sum(s, e, node, val);
        return;
    }
    lz(s, e, node);
    updatesum(s, md, lx, l, r, val), updatesum(md + 1, e, rx, l, r, val);
    tree[node] = mrg(tree[lx], tree[rx]);
}
ll query(int s, int e, int node, int l, int r){
    if(s > r || e < l)return 0;
    if(l <= s && e <= r)return tree[node].sum;
    lz(s, e, node);
    return query(s, md, lx, l, r) + query(md + 1, e, rx, l, r);
}
void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, n, 1);
    while(q--){
        int type;
        cin >> type;
        int l, r;
        cin >> l >> r;
        l++;
        if(type == 0){
            ll val;
            cin >> val;
            updatemn(1, n, 1, l, r, val); 
        }
        else if(type == 1){
            ll val;
            cin >> val;
            updatemx(1, n, 1, l, r, val);
        }
        else if(type == 2){
            ll val;
            cin >> val;
            updatesum(1, n, 1, l, r, val);
        }
        else {
            cout << query(1, n, 1, l, r) << "\n";
        }
    }
}
