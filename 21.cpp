#include<bits/stdc++.h>
#define ll long long
#define M 100050
using namespace std;
bool vis[M];
vector<ll>primes;
ll ans[M+5],aan[M+5];

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
    ll len = primes.size();
    ans[1]=0;
    for (ll i=2;i<=M;i++)
    {
        if (ans[i]==0)
        {
            ///cout<<1<<endl;
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
                ///cout<<primes[j]<<" "<<c<<endl;
                sum*=(ll)((pow(primes[j],c+1)-1)/(primes[j]-1));
            }
            ///cout<<sum<<endl;
            ///cout<<((pow(n,2.0)-1)/(n-1))<<endl;
            if (n>1)
            {
                ll t = ((pow(n*1.0,2)-1)/(n-1));
                ///cout<<t<<endl;
                sum*=t;
            }
            ///cout<<sum<<endl;

            ll tt = sum - i;
            if (i!=tt)
            {
                ll asum = 1;
                n = tt;
                ///cout<<n<<endl;
                for (ll j=0;primes[j]*primes[j]<=n;j++)
                {
                    ll c=0;
                    while(n%primes[j]==0)
                    {
                        n/=primes[j];
                        c++;
                    }
                    asum*=((pow(primes[j],c+1)-1)/(primes[j]-1));
                }
                if (n>1)
                {
                    ll t = ((pow(n*1.0,2)-1)/(n-1));
                    ///cout<<t<<endl;
                    asum*=t;
                }
                asum-=tt;
                ///cout<<asum<<" "<<tt<<endl;
                if (i==asum)
                {
                    ///cout<<i<<" "<<tt<<endl;
                    if (i<=M)
                        ans[i]=1;
                    if (tt<=M)
                        ans[tt]=1;
                }
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
        ll sm = 0;
        for (ll i=1;i<=N;i++)
        {
            if (ans[i]==1)
                sm+=i;
        }
        cout<<sm<<endl;
    }
    return 0;
}
