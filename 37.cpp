#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool vis[1005000];
vector<ll>primes,ans;
map<ll,ll>data;

void PrimeGenerator()
{
    memset(vis,true,sizeof(vis));
    vis[2]=false;
    primes.push_back(2);
    data[2]=1;
    for (ll i=3;i<=1000050;i+=2)
    {
        if (vis[i])
        {
            primes.push_back(i);
            data[i]=1;
            for (ll j=i*i;j<=1000050;j+=2*i)
                vis[j]=false;
        }
    }
}

void sett()
{
    ll len = primes.size();
    for (ll i=0;i<len;i++)
    {
        if (primes[i]>10)
        {
            ///cout<<primes[i]<<endl;
            ll cnt=0;
            ll n = primes[i];
            bool lft = false;
            ll c = 1;
            while(n!=0)
            {
                n/=10;
                cnt++;
                if (n!=0 && data[n]==1)
                    c++;
            }
            ///cout<<1<<endl;
            if (cnt==c)
                lft=true;
            bool rgt = false;
            ll div = 1;
            for (ll k=0;k<cnt-1;k++)
                div*=10;
            n=primes[i];
            c=1;
            ///cout<<div<<endl;
            while(div!=1)
            {
                ll rem = n%div;
                if (data[rem]==1)
                    c++;
                n=rem;
                div/=10;
            }
            ///cout<<2<<endl;
            if (cnt==c)
                rgt=true;
            if (lft&&rgt)
            {
                ans.push_back(primes[i]);
                ///cout<<primes[i]<<endl;
            }
        }
    }
}

int main ()
{
    PrimeGenerator();
    sett();
    ll N;
    while(cin>>N)
    {
        ll sum=0;
        ll len = ans.size();
        for (ll i=0;i<len && ans[i]<=N;i++)
            sum+=ans[i];
        cout<<sum<<endl;
    }
    return 0;
}
