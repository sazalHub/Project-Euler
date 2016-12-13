#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a,ll b)
{
    return (a%b)?gcd(b,a%b):b;
}

int main ()
{
    ll cases;
    cin>>cases;
    while(cases--)
    {
        ll N;
        cin>>N;
        ll ans = 1;
        for (ll i=1;i<=N;i++)
        {
            ll g = gcd(ans,i);
            ans = (ans*i)/g;
        }
        cout<<ans<<endl;
    }
    return 0;
}
