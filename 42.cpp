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
        ll bb = 1 + 8*N;
        ll rr = sqrt(bb);
        if (rr*rr != bb)
        {
            cout<<-1<<endl;
            continue;
        }
        ll ans = (rr-1)/2;
        cout<<ans<<endl;
    }
    return 0;
}
