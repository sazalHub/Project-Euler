#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main ()
{
    ll fact[15];
    fact[0]=1;
    for (ll i=1;i<=10;i++)
        fact[i] = i * fact[i-1];
    ll arr[100010];
    arr[9]=0;
    for (ll i=10;i<=100005;i++)
    {
        ll n = i;
        ll sum = 0;
        while(n!=0)
        {
            ll t = n%10;
            n/=10;
            sum+=fact[t];
        }
        if (sum%i==0)
            arr[i]=arr[i-1]+i;
        else
            arr[i]=arr[i-1];
    }
    ll N;
    while(cin>>N)
    {
        cout<<arr[N]<<endl;
    }
    return 0;
}
