#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool vis[10005005];
vector<ll>primes;

void PrimeGenerator()
{
    primes.push_back(2);
    for (ll i=3;i<=10000505;i+=2)
    {
        if (!vis[i])
        {
            primes.push_back(i);
            for (ll j=i*i;j<=10000505;j+=2*i)
                vis[j]=1;
        }
    }
}

ll check(ll N)
{
    if (N==1)
        return false;
    ll lnn = primes.size();
    for (ll i=0;i<lnn && primes[i]*primes[i]<=N;i++)
    {
        if (N%primes[i]==0)
            return false;
    }
    return true;
}

int main ()
{
    PrimeGenerator();
    vector<ll>ans;
    ll sze = primes.size();
    for (ll p=0;p<sze && primes[p]<=1000101;p++)
    {
        string xx = "";
        ll n = primes[p];
        while(n!=0)
        {
            xx+=(n%10+48);
            n/=10;
        }
        reverse(xx.begin(),xx.end());
        ll sm = 0;
        bool flag = true;
        ll len = xx.size();
        for (ll i=0;i<len && flag;i++)
        {
            ll sum = 0;
            ll ln = xx.size();
            for (ll j=i;j<ln;j++)
                sum = sum*10 + (xx[j]-48);
            if (!check(sum))
                flag = false;
            sm+=sum;
            xx+=xx[i];
        }
        if (flag)
            ans.push_back(primes[p]);
    }
    ll N;
    while(cin>>N)
    {
        ll len = ans.size();
        ll sum = 0;
        for (ll i=0;i<len && ans[i]<=N;i++)
            sum+=ans[i];
        cout<<sum<<endl;
    }
    return 0;
}
