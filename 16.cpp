#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct data{
    string xx;
    ll sum;
}arr[10005];

void sett()
{
    arr[1].xx = "2";
    arr[1].sum = 2;

    for (ll i=2;i<=10001;i++)
    {
        string ans = "";
        ll c = 0;
        string tmp = arr[i-1].xx;
        ll len = tmp.size();
        ll sm=0;
        for (ll j=0;j<len;j++)
        {
            ll t = tmp[j] - 48;
            t=t*2+c;
            sm+=t%10;
            ans+=(t%10+48);
            c=t/10;
        }
        while(c!=0)
        {
            sm+=c%10;
            ans+=(c%10+48);
            c=c/10;
        }
        arr[i].xx=ans;
        arr[i].sum=sm;
    }
}

int main ()
{
    ///cout<<(ll)pow(2,12)<<endl;
    sett();
    ll cases;
    cin>>cases;
    while(cases--)
    {
        ll N;
        cin>>N;
        cout<<arr[N].sum<<endl;
    }
    return 0;
}
