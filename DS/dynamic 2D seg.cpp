ll n , m , k ;
void init(int r, int c) {
    n = r , m = c ;
    k = 1 ;
}
struct op{
    int leftx , rightx , lefty , righty ;
    ll val ;
}tree[10000005];
deque < ll > se ;
void updatey(ll sy , ll ey , ll node , ll sx , ll ex , ll x , ll y , ll val){
    if(sy == ey){
        if(sx == ex){
            tree[node].val = val ;
        }
        else {
            ll op = se.front() ;
            se.pop_front() ;
            if(x <= mdx){
                if(!tree[node].leftx)tree[node].leftx = op ;
            }
            else {
                if(!tree[node].rightx)tree[node].rightx = op ;
            }
            tree[node].val = gcd2(tree[tree[node].leftx].val , tree[tree[node].rightx].val) ;
        }
        se.pb(node) ;
        R ;
    }
    if(y <= mdy){
        if(!tree[node].lefty){
            tree[node].lefty = ++k ;
        }
        updatey(sy , mdy , tree[node].lefty , sx , ex , x , y , val) ;
    }
    else {
        if(!tree[node].righty)tree[node].righty = ++k ;
        updatey(mdy + 1 , ey , tree[node].righty , sx , ex , x , y , val) ;
    }
    tree[node].val = gcd2(tree[tree[node].lefty].val , tree[tree[node].righty].val) ;
}
void updatex(ll sx , ll ex , ll node , ll x , ll y , ll val){
    if(sx != ex){
        if(x <= mdx){
            if(!tree[node].leftx)tree[node].leftx = ++k ;
            updatex(sx , mdx , tree[node].leftx , x , y , val) ;
        }
        else {
            if(!tree[node].rightx)tree[node].rightx = ++k ;
            updatex(mdx + 1 , ex , tree[node].rightx , x , y , val) ;
        }
    }
    updatey(0 , m - 1 , node , sx , ex , x , y , val) ;
}
ll queryy(ll sy , ll ey , ll node , ll ly , ll ry){
    if(sy > ry || ey < ly || !node)R 0 ;
    if(ly <= sy && ey <= ry)R tree[node].val ;
    R gcd2(queryy(sy , mdy , tree[node].lefty , ly , ry) , queryy(mdy + 1 , ey , tree[node].righty , ly , ry)) ;
}
ll queryx(ll sx , ll ex , ll node , ll lx , ll ly , ll rx , ll ry){
    if(sx > rx || ex < lx || !node)R 0 ;
    if(lx <= sx && ex <= rx){
        R queryy(0 , m - 1 , node , ly , ry) ;
    }
    R gcd2(queryx(sx , mdx , tree[node].leftx , lx , ly , rx , ry) , queryx(mdx + 1 , ex , tree[node].rightx , lx , ly , rx , ry)) ;
}
