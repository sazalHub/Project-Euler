#include<bits/stdc++.h>
#define ll long long
using namespace std;
string xx;

void doc(ll n,ll K)
{
    if (n==0)
        return;
    ll rem = n%K;
    doc(n/K,K);
    xx+=rem+48;
}

int main ()
{
    ll arr[100005],j=0;
    ///memset(arr,0,sizeof(arr));
    for (ll i=1;i<=1000002;i++)
    {
        ll num = 0;
        ll n = i;
        while(n!=0)
        {
            num = num*10 + n%10;
            n/=10;
        }
        if (i==num)
            arr[j++]=i;
    }
    ll N,K;
    while(cin>>N>>K)
    {
        ll sum = 0;
        for (ll i=0;i<j;i++)
        {
            if (arr[i]<=N)
            {
                xx="";
                doc(arr[i],K);
                string yy=xx;
                reverse(yy.begin(),yy.end());
                if (xx==yy)
                    sum+=arr[i];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
