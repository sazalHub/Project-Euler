#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
    ll arr[1010];
    arr[0]=1,arr[1]=1;
    string xx = "1";
    for (ll i=2;i<=1005;i++)
    {
        string tmp = "";
        ll t = i;
        while(t!=0)
        {
            tmp+=(t%10)+48;
            t/=10;
        }
        ///cout<<xx<<" "<<tmp<<endl;
        string tp[100];
        ll j=0;
        ll len = 0;

        for (ll l=0;l<tmp.size();l++)
        {
            string tem = "";
            for (ll k=0;k<j;k++)
                tem+="0";
            ll c = 0;
            for (ll k=0;k<xx.size();k++)
            {
                ll sum = c + (xx[k]-48)*(tmp[l]-48);
                tem+=(sum%10)+48;
                c=sum/10;
            }
            while(c!=0)
            {
                tem+=(c%10)+48;
                c/=10;
            }
            if (len<tem.size())
                len=tem.size();
            ///cout<<tem<<endl;
            tp[j++]=tem;
            ///cout<<tmp<<endl;
        }
        string tans = "";
        ll c = 0;
        for (ll k=0;k<len;k++)
        {
            ll sm = c;
            for (ll l=0;l<j;l++)
            {
                if (k<tp[l].size())
                    sm+=tp[l][k]-48;
            }
            tans+=(sm%10)+48;
            c=sm/10;
        }
        while(c!=0)
        {
            tans+=(c%10)+48;
            c/=10;
        }
        xx=tans;
        ll sum = 0;
        ///reverse(tans.begin(),tans.end());
        ///cout<<i<<" "<<tans<<endl;
        for (ll k=0;k<tans.size();k++)
            sum+=(tans[k]-48);
        arr[i]=sum;
    }
    ll cases;
    cin>>cases;
    while(cases--)
    {
        ll N;
        cin>>N;
        cout<<arr[N]<<endl;
    }
    return 0;
}
