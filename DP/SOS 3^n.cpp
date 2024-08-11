
void solve(){
    for(int msk = mask & (mask - 1); msk > 0; msk = mask & (msk - 1)){
        r = max(r, mem(msk) + mem(msk ^ mask));
    }
}
