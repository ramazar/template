ll lpf[1000001],mobius[1000001];
void least_prime_factor()
{
    for(int i=2;i<1000001;i++)
    {
    if(!lpf[i])
    {
        for(int j=i;j<1000001;j+=i)
        {
            if(!lpf[j]) lpf[j]=i;
        }
    }
}
}
void Mobius()
{
    for(int i=1;i<1000001;i++)
    {
        if(i==1) mobius[i]=1;
        else
        {
            if(lpf[i/lpf[i]]==lpf[i])mobius[i]=0;
            else mobius[i]=-1*mobius[i/lpf[i]];
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll x[n],cnt[1000001]={};
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
        cnt[x[i]]++;
    }
    least_prime_factor();
    Mobius();
    ll ans=0;
    for(int i=1;i<1000001;i++)
    {
    if(mobius[i]==0) continue;
    ll d=0;
    for(int j=i;j<1000001;j+=i)
    {
        d+=cnt[j];
    }
    ans+=(d*(d-1))/2*mobius[i];
    }
    cout<<ans;
}
