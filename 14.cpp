#include<bits/stdc++.h>
#define ll long long
#define sze 5000005
using namespace std;
ll dp[sze];
ll ar[sze];

int main ()
{

    dp[1]=0;
    dp[2]=1;

    for (ll i=3;i<=sze;i+=2)
    {
        ///cout<<i<<endl;
        ll c = 0;
        ll n = i;
        while(n!=1)
        {
            if (n%2==0)
                n/=2;
            else
                n=n*3+1;
            c++;
            ///cout<<n<<endl;
        }
        ///cout<<2<<endl;
        dp[i]=c;
        for (ll j=i*2;j<=sze;j*=2)
        {
            dp[j]=dp[(ll)(j/2)]+1;
        }
    }

    ll ans=0;
    ar[0]=1;
    for (ll i=1;i<sze;i++)
    {
        if (ans<=dp[i])
        {
            ans=dp[i];
            ar[i]=i;
        }
        else
        {
            ar[i]=ar[i-1];
        }
    }

    ll cases;
    cin>>cases;
    while(cases--)
    {
        ll N;
        cin>>N;
        cout<<ar[N]<<endl;
    }
    return 0;
}
