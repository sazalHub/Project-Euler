#include<bits/stdc++.h>
#define ll long long
#define M 2000505
using namespace std;
bool vis[M];
vector<ll>primes;
map<ll,vector<ll> >arr;

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

void sett()
{
    ll len = primes.size();
    for (ll i=1;i<=1000005;i++)
    {
        ll n = i;
        ll cnt = 0;
        for (ll j=0;j<len && primes[j]*primes[j]<=n;j++)
        {
            ll c=0;
            while(n%primes[j]==0 && n>=primes[j])
            {
                n/=primes[j];
                c++;
            }
            if (c>0)
                cnt++;
        }
        if (n>1)
            cnt++;
        arr[cnt].push_back(i);
    }
}

int main ()
{
    PrimeGenerator();
    sett();

    ll N,K;
    while(cin>>N>>K)
    {
        ll ln = arr[K].size();
        vector<ll>ans;

        for (ll i=0;i<ln;i++)
        {
            ll fs = arr[K][i];
            ll c = 1,k = i+1,j = 1;
            for (;j<K;j++)
            {
                if (fs+1!=arr[K][k])
                    break;
                fs = arr[K][k++];
            }
            if (j==K)
                ans.push_back(arr[K][i]);
        }
        ln = ans.size();
        for (ll i=0;i<ln;i++)
        {
            if (ans[i]<=N)
                cout<<arr[K][i]<<endl;
            else
                break;
        }
    }
    return 0;
}

