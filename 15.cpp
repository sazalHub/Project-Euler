#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll gcd(ll a,ll b)
{
    return (a%b)?gcd(b,a%b):b;
}

ll sett(ll u,ll n,ll m)
{
    vector<ll>arr;
    for (ll i=max(n,m)+1;i<=u;i++)
        arr.push_back(i);
    ll ar[u+5];
    for (ll i=1;i<=min(n,m);i++)
        ar[i]=i;
    for (ll i=1;i<=min(n,m);i++)
    {
        if (ar[i]!=1)
        {
            for (ll j=0;j<arr.size() && ar[i]>1;j++)
            {
                ll g = gcd(ar[i],arr[j]);
                arr[j]/=g;
                ar[i]/=g;
            }
        }
    }
    ll ans = 1;
    for (ll i=0;i<arr.size();i++)
        ans = ((ans%mod)*(arr[i]%mod))%mod;
    return ans;
}

int main ()
{
    ll cases;
    cin>>cases;
    while(cases--)
    {
        ll n,m;
        cin>>n>>m;
        ll u = n+m;
        ll ans = sett(u,n,m);
        cout<<ans<<endl;
    }
    return 0;
}
