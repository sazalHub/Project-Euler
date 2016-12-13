#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll coins[] = {1,2,5,10,20,50,100,200};
ll dp[10][100005];

ll sett(ll i,ll w)
{
    if (i>=8)
    {
        if (w==0)
            return 1;
        else
            return 0;
    }
    if (dp[i][w]!=-1)
        return dp[i][w];
    ll ret1=0,ret2=0;
    if (w-coins[i]>=0)
        ret1 = sett(i,w-coins[i]);
    ret2 = sett(i+1,w);
    return dp[i][w] = (ret1%mod + ret2%mod)%mod;
}

int main ()
{
    memset(dp,-1,sizeof(dp));
    ll cases;
    cin>>cases;
    while(cases--)
    {
        ll N;
        cin>>N;
        ll ans = sett(0,N);
        cout<<ans<<endl;
    }
    return 0;
}
