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

struct detail {
    ll sum;
    ll lastP;
}arr[1000005];

int main ()
{
    PrimeGenerator();
    ll len = primes.size();
    arr[0].sum = primes[0];
    arr[0].lastP = primes[0];
    for (ll i=1;i<len;i++)
    {
        arr[i].sum = arr[i-1].sum + primes[i];
        arr[i].lastP=primes[i];
    }
    ll cases;
    cin>>cases;
    while(cases--)
    {
        ll N;
        cin>>N;
        ll ans = 0;
        for (ll i=0;i<len;i++)
        {
            if (arr[i].lastP>N)
                break;
            ans = arr[i].sum;
        }
        cout<<ans<<endl;
    }
    return 0;
}

