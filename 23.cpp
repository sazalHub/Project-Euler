#include<bits/stdc++.h>
#define ll long long
#define M 100050
using namespace std;
bool vis[M];
vector<ll>primes,abd;

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
    ///cout<<"ses"<<endl;
}

void sett()
{
    map<ll,ll>yes;
    ll len = primes.size();
    for (ll i=1;i<=M;i++)
    {
        ll sum = 1;
        ll n = i;
        for (ll j=0;primes[j]*primes[j]<=n;j++)
        {
            ll c=0;
            while(n%primes[j]==0)
            {
                n/=primes[j];
                c++;
            }
            sum*=(ll)((pow(primes[j],c+1)-1)/(primes[j]-1));
        }
        if (n>1)
        {
            ll t = ((pow(n*1.0,2)-1)/(n-1));
            sum*=t;
        }
        sum-=i;
        if (sum>i)
        {
            abd.push_back(i);
            yes[i]=1;
        }
    }
    memset(vis,false,sizeof(vis));
    len = abd.size();
    for (ll i=1;i<=M;i++)
    {
        for (ll j=0;j<len && i>=abd[j];j++)
        {
            ll tm = i - abd[j];
            if (yes[tm]==1)
            {
                vis[i]=true;
                break;
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
        if (vis[N])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}

