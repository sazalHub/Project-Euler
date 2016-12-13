#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
    ll cases;
    cin>>cases;
    while(cases--)
    {
        ll N;
        cin>>N;
        N--;
        ll sum5=0,sum3=0,tsum3=0,tsum15=0;
        if ((N-5)>=0)
        {
            ll n5 = (ll)(N-5)/5 + 1;
            sum5 = n5*(10+(n5-1)*5)/2;
        }
        if ((N-3)>=0)
        {
            ll n3 = (ll)(N-3)/3 + 1;
            tsum3 = n3*(6+(n3-1)*3)/2;
        }
        if ((N-15)>=0)
        {
            ll n15 = (ll)(N-15)/15 + 1;
            tsum15 = n15*(30+(n15-1)*15)/2;
        }
        sum3 = tsum3 - tsum15;
        ll ans = sum5 + sum3;
        cout<<ans<<endl;
    }
    return 0;
}
