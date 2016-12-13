#include<bits/stdc++.h>
#define ll long long
#define M 505050
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
        ll cnt = 0;
        for (ll i=0;i<len && primes[i]<N;i++)
        {
            ll rem = N - primes[i];
            if (rem%2==0)
            {
                ll rm = rem/2;
                ll srt = sqrt(rm);
                if (srt*srt==rm)
                    cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}


