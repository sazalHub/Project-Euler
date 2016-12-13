#include<bits/stdc++.h>
#define ll long long
#define M 105005
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
    ///cout<<primes.size()<<endl;
    ll cases;
    cin>>cases;
    while(cases--)
    {
        ll N;
        cin>>N;
        cout<<primes[N-1]<<endl;
    }
    return 0;
}

