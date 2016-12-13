#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main ()
{
    ll cases;
    cin>>cases;
    while(cases--)
    {
        ll N,K;
        cin>>N>>K;
        string txt;
        cin>>txt;
        ll ans = 0;
        for (ll i=0;i<=N-K;i++)
        {
            ll pro = txt[i] - 48;
            ll k=0;
            for (ll j=i+1,k=0;k<K-1;j++,k++)
                pro = pro * (txt[j]-48);
            if (ans<pro)
                ans = pro;
        }
        cout<<ans<<endl;
    }
    return 0;
}
