#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>palindromes;

bool isPalin(ll n)
{
    ll num=0,t=n;
    while(t!=0)
    {
        ll r = t%10;
        t/=10;
        num=num*10+r;
    }
    if (n==num)
        return true;
    else
        return false;
}


void PalinGenerator()
{
    for (ll i=100;i<=999;i++)
    {
        for (ll j=100;j<=999;j++)
        {
            ll product = i*j;
            if (isPalin(product))
            {
                ///cout<<product<<endl;
                palindromes.push_back(product);
            }
        }
    }
    ///cout<<palindromes.size()<<endl;
}

int main ()
{
    PalinGenerator();
    ll len = palindromes.size();
    ll cases;
    cin>>cases;
    while(cases--)
    {
        ll N;
        cin>>N;
        ll ans=-1;
        for (ll i=0;i<len;i++)
        {
            if (palindromes[i]<N)
            {
                if (ans<palindromes[i])
                    ans=palindromes[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
