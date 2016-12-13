#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool vis[10005];
vector<ll>primes;
ll len;
ll dp[1005][1005];

void PrimeGenerator()
{
    memset(vis,false,sizeof(vis));
    primes.push_back(2);
    for (ll i=3;i<=10004;i+=2)
    {
        if (!vis[i])
        {
            ///cout<<i<<endl;
            primes.push_back(i);
            for (ll j=i*i;j<=10004;j+=2*i)
                vis[j] = true;
        }
    }
    len = primes.size();
}

ll sett(ll N,ll i)
{
    if (N==0)
        return 1;
    if (i==len)
    {
        if (N==0)
            return 1;
        else
            return 0;
    }

    if (N<primes[i])
        return 0;

    if (dp[N][primes[i]]!=-1)
        return dp[N][primes[i]];

    ll pro1 = 0,pro2 = 0;
    if (N-primes[i]>=0)
        pro1 = sett(N-primes[i],i);
    pro2 = sett(N,i+1);
    return dp[N][primes[i]] = pro1 + pro2;
}

int main ()
{
    PrimeGenerator();
    memset(dp,-1,sizeof(dp));
    ll n;
    ll cases;
    cin>>cases;
    while(cases--)
    {
        ll n;
        cin>>n;
        ll ans = sett(n,0);
        cout<<ans<<endl;
    }
    return 0;
}
