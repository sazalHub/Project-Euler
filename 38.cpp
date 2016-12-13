#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,vector<ll> >ans;

void sett()
{
    for (ll i=2;i<=100005;i++)
    {
        ll arr[10];
        for (ll j=0;j<=9;j++)
            arr[j]=0;
        ll tmp = i;
        ll mul = 1;
        bool fl = true;
        while(fl)
        {
            ll m = tmp*mul;
            while(m!=0)
            {
                ll rem = m%10;
                m/=10;
                if (rem==0 || rem==9)
                {
                    fl=false;
                    break;
                }
                if (arr[rem]>0)
                {
                    fl=false;
                    break;
                }
                else
                    arr[rem]++;
            }
            ll c=0;
            for (ll i=1;i<=8;i++)
                if (arr[i]==1)
                    c++;
            if (c==8)
                break;
            mul++;
        }
        if (fl)
        {
            ///cout<<i<<endl;
            ans[8].push_back(i);
        }

        for (ll j=0;j<=9;j++)
            arr[j]=0;
        tmp = i;
        mul = 1;
        fl = true;
        while(fl)
        {
            ll m = tmp*mul;
            while(m!=0)
            {
                ll rem = m%10;
                m/=10;
                if (rem==0)
                {
                    fl=false;
                    break;
                }
                if (arr[rem]>0)
                {
                    fl=false;
                    break;
                }
                else
                    arr[rem]++;
            }
            ll c=0;
            for (ll i=1;i<=9;i++)
                if (arr[i]==1)
                    c++;
            if (c==9)
                break;
            mul++;
        }
        if (fl)
            ans[9].push_back(i);


    }
}
int main ()
{
    sett();
    ll n,k;
    while(cin>>n>>k)
    {
        ll len = ans[k].size();
        for (ll i=0;i<len && ans[k][i]<=n;i++)
        {
            cout<<ans[k][i]<<endl;
        }
    }
    return 0;
}
