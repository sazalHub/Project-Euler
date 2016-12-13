#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
    ll N;
    while(cin>>N)
    {
        string str[N+5];
        for (ll i=0;i<N;i++)
            cin>>str[i];
        string ans = "";
        ll carry = 0;
        for (ll i=49;i>=0;i--)
        {
            ll sum = carry;
            for (ll j=0;j<N;j++)
                sum+=(str[j][i]-48);
            ans+=(sum%10+48);
            carry=sum/10;
        }
        while(carry!=0)
        {
            ans+=(carry%10+48);
            carry/=10;
        }
        reverse(ans.begin(),ans.end());
        ///cout<<ans<<endl;
        ///string tn = "";
        ll i=0;
        while(ans[i]=='0' && i<ans.size())
            i++;
        for (ll k=0;k<10;i++,k++)
            cout<<ans[i];
        cout<<endl;
    }
    return 0;
}
