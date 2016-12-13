#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define M 1000505
bool vis[M];
vector<ll>primes;

struct data{
    ll div;
    ll num;
}arr[100005];
ll lnt=0;

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
    for (ll i=1;i<=41100;i++)
    {
        ll div=1;
        ll n = (i*(i+1))/2;
        ll ln = n;
        ll len = primes.size();
        for (ll j=0;primes[j]*primes[j] <= n;j++)
        {
            ll c=0;
            while(n%primes[j]==0 && n>=primes[j])
            {
                n/=primes[j];
                c++;
            }
            div*=(c+1);
        }
        if (n>1)
            div*=2;
        if (lnt==0)
        {
            arr[lnt].num=ln;
            arr[lnt++].div=div;
        }
        else
        {
            if (arr[lnt-1].div<div)
            {
                arr[lnt].num=ln;
                arr[lnt++].div=div;
            }
        }
    }
}

int main ()
{
    PrimeGenerator();
    sett();

    ll cases;
    cin>>cases;
    while(cases--)
    {
        ll N;
        cin>>N;
        for (ll i=0;i<lnt;i++)
        {
            if (arr[i].div>N)
            {
                cout<<(arr[i].num)<<endl;
                break;
            }
        }
    }
    return 0;
}
