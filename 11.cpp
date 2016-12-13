#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
    ll arr[30][30];

    for (ll i=0;i<20;i++)
        for (ll j=0;j<20;j++)
            cin>>arr[i][j];

    ll srt = 0;
    for (ll i=0;i<20;i++)
    {
        for (ll j=0;j<20;j++)
        {
            if ((j+3)<20)
            {
                ll pro = 1;
                for (ll k=0;k<4;k++)
                {
                    pro=pro*arr[i][j+k];
                }
                if (pro>srt)
                    srt=pro;
            }

            if ((j-3)>=0)
            {
                ll pro = 1;
                for (ll k=0;k<4;k++)
                {
                    pro=pro*arr[i][j-k];
                }
                if (pro>srt)
                    srt=pro;
            }

            if ((i+3)<20)
            {
                ll pro = 1;
                for (ll k=0;k<4;k++)
                {
                    pro=pro*arr[i+k][j];
                }
                if (pro>srt)
                    srt=pro;
            }

            if ((i-3)>=0)
            {
                ll pro = 1;
                for (ll k=0;k<4;k++)
                {
                    pro=pro*arr[i-k][j];
                }
                if (pro>srt)
                    srt=pro;
            }

            if ((i+3)<20 && (j+3)<20)
            {
                ll pro = 1;
                for (ll k=0;k<4;k++)
                {
                    pro=pro*arr[i+k][j+k];
                }
                if (pro>srt)
                    srt=pro;
            }

            if ((i+3)<20 && (j-3)>=0)
            {
                ll pro = 1;
                for (ll k=0;k<4;k++)
                {
                    pro=pro*arr[i+k][j-k];
                }
                if (pro>srt)
                    srt=pro;
            }

            if ((i-3)>=0 && (j+3)<20)
            {
                ll pro = 1;
                for (ll k=0;k<4;k++)
                {
                    pro=pro*arr[i-k][j+k];
                }
                if (pro>srt)
                    srt=pro;
            }

            if ((i-3)>=0 && (j-3)>=0)
            {
                ll pro = 1;
                for (ll k=0;k<4;k++)
                {
                    pro=pro*arr[i-k][j-k];
                }
                if (pro>srt)
                    srt=pro;
            }

        }
    }



    cout<<srt<<endl;


    return 0;
}
