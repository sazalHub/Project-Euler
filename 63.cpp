#include<bits/stdc++.h>
#define ll long long unsigned
using namespace std;
int main ()
{
    ll N;
    while(cin>>N)
    {
        ll lst = 1;
        for (ll i=0;i<N-1;i++)
            lst*=10;
        ll hst = 9;
        if (N==19)
            hst = 8;
        for (ll i=0;i<N-1;i++)
            hst = hst*10 + 9;
        ///cout<<lst<<" "<<hst<<endl;
        bool fl = true;
        for (ll i=1;fl;i++)
        {
            ll pwr = 1;
            for (ll p=1;p<=N && fl;p++)
            {
                ///cout<<p<<endl;
               pwr = pwr * i;
               if (pwr>hst)
                    fl = false;
            }
            if (pwr>=lst && pwr<=hst && fl)
                cout<<pwr<<endl;
        }
    }
    return 0;
}
