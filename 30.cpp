#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main ()
{
    map<ll,ll>data;
    data[3] = 1301;
    data[4] = 19316;
    data[5] = 443839;
    data[6] = 548834;
    ll n;
    while(cin>>n)
        cout<<data[n]<<endl;
    return 0;
}
