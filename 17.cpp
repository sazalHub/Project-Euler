#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
    map<ll,string>ml;
    ml[1]="One";
    ml[2]="Two",ml[3]="Three",ml[4]="Four";
    ml[5]="Five",ml[6]="Six",ml[7]="Seven";
    ml[8]="Eight",ml[9]="Nine",ml[10]="Ten";
    ml[11]="Eleven",ml[12]="Twelve",ml[13]="Thirteen";
    ml[14]="Fourteen",ml[15]="Fifteen",ml[16]="Sixteen";
    ml[17]="Seventeen",ml[18]="Eighteen",ml[19]="Nineteen";
    ml[20]="Twenty";
    ml[30]="Thirty",ml[40]="Fourty",ml[50]="Fifty";
    ml[60]="Sixty",ml[70]="Seventy",ml[80]="Eighty";
    ml[90]="Ninety";

    ll cases;
    cin>>cases;
    while(cases--)
    {
        ll N;
        cin>>N;
        ll bln = N/1000000000;
        N=N%1000000000;

        ll mln = N/1000000;
        N=N%1000000;

        ll ths = N/1000;
        N=N%1000;

        ///cout<<bln<<" "<<mln<<" "<<ths<<endl;

        bool bll=true,mll=true;

        if (bln>0)
        {
            bll=false;
            bool f1=true,f2=true,f3=true;
            if (bln>=1000)
            {
                ll th = bln/1000;
                cout<<ml[th]<<" Thousand";
                bln=bln%1000;
                f1=false;
            }
            if (bln>=100)
            {
                f2=false;
                ll th = bln/100;
                if (!f1)
                    cout<<" ";
                cout<<ml[th]<<" Hundred";
                bln=bln%100;
            }
            if (bln>=20)
            {
                ll th = (bln/10)*10;
                if (!f2)
                    cout<<" ";
                cout<<ml[th];
                if (bln%10!=0)
                    cout<<" "<<ml[bln%10];
            }
            else
            {
                if (!f1 || !f2)
                    cout<<" ";
                cout<<ml[bln];
            }
            cout<<" Billion";
        }

        if (mln>0)
        {
            mll=false;
            if (!bll)
                cout<<" ";
            bool f1=true,f2=true;
            if (mln>=100)
            {
                f1=false;
                ll th = mln/100;
                cout<<ml[th]<<" Hundred";
                mln=mln%100;
            }
            if (mln>=20)
            {
                f2=false;
                if (!f1)
                    cout<<" ";
                ll th = (mln/10)*10;
                cout<<ml[th];
                if (mln%10!=0)
                    cout<<" "<<ml[mln%10];
            }
            else
            {
                if (!f1)
                    cout<<" ";
                cout<<ml[mln];
            }
            cout<<" Million";
        }

        if (ths>0)
        {
            if (!bll || !mll)
                cout<<" ";
            bool f1=true,f2=true;
            if (ths>=100)
            {
                f1=false;
                ll th = ths/100;
                cout<<ml[th]<<" Hundred";
                ths=ths%100;
            }
            if (ths>=20)
            {
                f2=false;
                if (!f1)
                    cout<<" ";
                ll th = (ths/10)*10;
                cout<<ml[th];
                if (ths%10!=0)
                    cout<<" "<<ml[ths%10];
            }
            else
            {
                if (!f1)
                    cout<<" ";
                cout<<ml[ths];
            }
            cout<<" Thousand";
        }

        bool fl = true;
        if (!bll || !mll)
            cout<<" ";
        if (N>=100)
        {
            ll th = N/100;
            cout<<ml[th]<<" Hundred";
            N=N%100;
            fl=false;
        }
        if (N>=20)
        {
            ll th = (N/10)*10;
            cout<<ml[th];
            if (N%10!=0)
                cout<<" "<<ml[N%10];
            fl = false;
        }
        else
        {
            if (!fl)
                cout<<" ";
            cout<<ml[N];
        }
        cout<<endl;

    }
    return 0;
}
