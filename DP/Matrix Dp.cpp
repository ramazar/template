const int mod = 1e9 + 7;
struct Matrix{
    int N = 2;
    ll a[2][2];
    Matrix(){}
    void Zero(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                a[i][j] = 0;
            }
        }
    }
    void one(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                a[i][j] = (i == j);
            }
        }
    }
    Matrix operator * (Matrix B){
        Matrix ret, A = *this;
        ret.Zero();
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                for(int k = 0; k < N; k++){
                    ret.a[i][j] = (ret.a[i][j] + A.a[i][k] * B.a[k][j] % mod) % mod;
                }
            }
        }
        return ret;
    }
    Matrix pwr(ll K){
        Matrix ret, A = *this;
        ret.one();
        while(K){
            if(K & 1){
                ret = ret * A;
            }
            A = A * A;
            K >>= 1;
        }
        return ret;
    }
};
ll n;
void solve(){
    Matrix ans;
    ans.Zero();
    ans.a[0][1] = ans.a[1][0] = ans.a[1][1] = 1;
    cin >> n;
    if(!n){
        cout << 0 << "\n";
        return;
    }
    cout << ans.pwr(n - 1).a[1][1] << "\n";
}
