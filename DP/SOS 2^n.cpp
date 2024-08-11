void solve(){
    for(int j = 0; j < 20; j++){
        for(int mask = 0; mask < (1 << 20); mask++)[
            if(mask & (1 << j)){
                dp[mask] += dp[mask ^ (1 << j)];
            }
        }
    }
}
