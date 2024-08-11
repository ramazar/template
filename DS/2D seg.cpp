int n , m , k ;
#define lxx nodex * 2
#define rxx nodex * 2 + 1
#define lxy nodey * 2
#define rxy nodey * 2 + 1
#define mdx ((sx + ex) / 2)
#define mdy ((sy + ey) / 2)
ll tree[8005][8005] ;
void updatey(int sy, int ey, int nodey, int sx, int ex, int nodex, int x, int y, ll val){
    if(sy == ey){
        if(sx == ex)tree[nodex][nodey] = val;
        else tree[nodex][nodey] = mrg(tree[lxx][nodey], tree[rxx][nodey]);
        return;
    }
    if(y <= mdy)updatey(sy, mdy, lxy, sx, ex, nodex, x, y, val);
    else updatey(mdy + 1, ey, rxy, sx, ex, nodex, x, y, val);
    tree[nodex][nodey] = mrg(tree[nodex][lxy], tree[nodex][rxy]);
}
void updatex(int sx, int ex, int nodex, int x, int y, ll val){
    if(sx != ex){
        if(x <= mdx)updatex(sx, mdx, lxx, x, y, val);
        else updatex(mdx + 1, ex, rxx, x, y, val);
    }
    updatey(0, m - 1, 1, sx, ex, nodex, x, y, val);
}
ll queryy(int sy, int ey, int nodey, int nodex, int ly, int ry){
    if(sy > ry || ey < ly)return 0;
    if(ly <= sy && ey <= ry)return tree[nodex][nodey];
    return mrg(queryy(sy, mdy, lxy, nodex, ly, ry), queryy(mdy + 1, ey, rxy, nodex, ly, ry));
}
ll queryx(int sx, int ex, int nodex, int lx, int ly, int rx, int ry){
    if(sx > rx || ex < lx)return 0;
    if(lx <= sx && ex <= rx){
        return queryy(0, m - 1, 1, nodex, ly, ry);
    }
    return mrg(queryx(sx, mdx, lxx, lx, ly, rx, ry), queryx(mdx + 1, ex, rxx, lx, ly, rx, ry));
}

