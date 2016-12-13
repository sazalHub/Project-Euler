#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans[30005];
void solve()
{
    ans[0] = 0;
    for (ll i=1;i<=30001;i++)
    {
        ///cout<<" i = ";
        ll a0 = sqrt(i);
        ll result = 0;
        if (a0*a0!=i)
        {
            ll a = a0;
            ll m = 0;
            ll d = 1;
            ll period = 0;
            while(a!=2*a0)
            {
                m = d*a - m;
                d = (i - m*m)/d;
                a = (a0 + m)/d;
                period++;
            }
            if (period%2==1)
            {
                ///cout<<1<<" ";
                result = 1;
            }
        }
        ans[i] = ans[i-1] + result;
        ///cout<<i<<" "<<ans[i]<<endl;
    }
}

int main ()
{
    ll N;
    solve();
    while(cin>>N)
    {
        printf("%lld\n",ans[N]);
    }
    return 0;
}
