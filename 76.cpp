#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll dp[1015][1015];
ll arr[1015],mid,n;

ll sett(ll i,ll N)
{
    ///cout<<N<<" "<<i<<endl;
    if (N==0)
        return 1;
    if (N<arr[i])
        return 0;
    if (dp[N][arr[i]]!=-1)
        return dp[N][arr[i]]%mod;
    ll pro1 = 0,pro2 = 0;
    if (N-arr[i]>=0)
        pro1 = sett(i,N-arr[i]);
    pro2 = sett(i+1,N);
    return dp[N][arr[i]] = (pro1%mod + pro2%mod)%mod;
}

int main ()
{
    for (ll i=0;i<=1010;i++)
        arr[i] = i;
    memset(dp,-1,sizeof(dp));
    ll cases;
    cin>>cases;
    while(cases--)
    {
        cin>>n;
        mid=n/2;
        ll ans = sett(1,n)%mod;
        cout<<(ans-1)%mod<<endl;
    }
    return 0;
}
