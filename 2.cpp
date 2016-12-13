#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main ()
{
    ll fib[105];
    fib[1]=1;fib[2]=2;
    for (ll i=3;;i++)
    {
        ll sum = fib[i-1] + fib[i-2];
        if (sum>(1000000000000000000))
        {
            ///cout<<i<<endl;
            break;
        }
        fib[i]=sum;
        ///cout<<fib[i]<<endl;
    }

    ll cases;
    cin>>cases;
    while(cases--)
    {
        ll N;
        cin>>N;
        ll sum=0;
        for (ll i=2;i<87;i+=3)
        {
            ///cout<<i<<" "<<fib[i]<<endl;
            if (fib[i]>N)
                break;
            sum+=fib[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
