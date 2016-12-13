#include<bits/stdc++.h>
#define ll unsigned long long
#define mod 100000000
using namespace std;
ll arr[2000005];
ll ret,y;

ll pwr (ll base,ll power)
{
    if (power==0)
        return 1;
    if (power%2==0)
    {
        ret = pwr(base,power/2);
        y = ((ret%mod)*(ret%mod))%mod;
    }
    else
    {
        ret = pwr(base,power/2);
        y = ((base%mod)*((ret%mod)*(ret%mod))%mod)%mod;
    }
    return y%mod;
}

int main ()
{
    ll sum = 0,sum1 = 0;
    for (ll i=1;i<=1005;i++)
    {
        ll sm1 = pwr(i,i);
        ll sm=1;
        ll md = 10000000000;
        for (ll j=1;j<=i;j++)
            sm = ((i%md)*(sm%md))%md;
        sum1=((sum1%md)+(sm%md))%md;
        sum=((sum%mod)+(sm1%mod))%mod;
        arr[i] = sum%mod;
        cout<<i<<" "<<arr[i]<<" "<<sum1<<" "<<sum1/mod<<endl;
    }
    ll N;
    while(cin>>N)
    {
        cout<<arr[N]<<endl;
    }
    return 0;
}
