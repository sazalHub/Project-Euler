#include<bits/stdc++.h>
#define ll long long
#define M 1000505
using namespace std;
bool vis[M];
vector<ll>primes;

void PrimeGenerator()
{
    memset(vis,true,sizeof(vis));
    primes.push_back(2);
    ///vis[2]=false;
    for (ll i=3;i<=M;i+=2)
    {
        if (vis[i])
        {
            ///cout<<i<<endl;
            primes.push_back(i);
            for (ll j=i*i;j<=M;j+=2*i)
                vis[j]=false;
        }
    }
}

int main ()
{
    PrimeGenerator();
    ll len = primes.size();
    ll cases;
    cin>>cases;
    while(cases--)
    {
        ll N;
        cin>>N;
        ///cout<<vis[N]<<endl;
        ll lmt = sqrt(N) + 5;
        ll ans=-1;
        ll temp=N;
        for (ll i=0;i<len && primes[i]<=temp;i++)
        {
            ll tm = temp;
            while(temp%primes[i]==0)
                temp/=primes[i];
            if (temp!=tm)
                if (ans<primes[i])
                    ans=primes[i];
        }
        if (temp>1 && ans<temp)
            ans = temp;
        if (ans==-1)
            ans=N;
        cout<<ans<<endl;
    }
    return 0;
}
