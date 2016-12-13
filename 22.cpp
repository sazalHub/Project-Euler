#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
    map<char,ll>arr;
    for (ll i=1;i<=26;i++)
    {
        char ch = i + 64;
        ///cout<<ch<<endl;
        arr[ch]=i;
    }
    for (ll i=1;i<=26;i++)
    {
        char ch = i + 96;
        ///cout<<ch<<endl;
        arr[ch]=i;
    }

    ll N;
    while(cin>>N)
    {
        string xx[N+5];
        map<string,ll>worth;
        for (ll i=0;i<N;i++)
            cin>>xx[i];

        sort(xx,xx+N);
        for (ll i=0;i<N;i++)
        {
            ll len = xx[i].size();
            for (ll j=0;j<len;j++)
                worth[xx[i]]+=arr[xx[i][j]];
            worth[xx[i]]*=(i+1);
        }
        ll Q;
        cin>>Q;
        for (ll i=0;i<Q;i++)
        {
            string x;
            cin>>x;
            cout<<worth[x]<<endl;
        }
        worth.clear();
    }
    return 0;
}
