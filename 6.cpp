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
        ll ans1 = N*(N+1)/2;
        ans1=ans1*ans1;
        ll ans2 = (N*(2*N+1)*(N+1))/6;
        ll ans = ans1 - ans2;
        cout<<ans<<endl;
    }
    return 0;
}
