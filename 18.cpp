#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[20][20],N,ret;

void sett(ll i,ll j,ll w)
{
    ///cout<<i<<" "<<j<<" "<<w<<endl;
    if (i==N)
    {
        ///cout<<1<<endl;
        if (ret<w)
            ret=w;
        return;
    }
    sett(i+1,j,w+arr[i][j]);
    sett(i+1,j+1,w+arr[i][j]);
}

int main ()
{
    ll cases;
    cin>>cases;
    while(cases--)
    {
        cin>>N;
        for (ll i=0;i<N;i++)
            for (ll j=0;j<=i;j++)
                cin>>arr[i][j];

        ret=0;
        sett(0,0,0);
        cout<<ret<<endl;
    }
    return 0;
}
