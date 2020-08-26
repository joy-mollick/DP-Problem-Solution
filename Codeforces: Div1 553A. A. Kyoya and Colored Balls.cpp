
/// Codeforces: Div1 553A. A. Kyoya and Colored Balls
/// Category : dp+combinatorics. an easy one .

#include<bits/stdc++.h>

using namespace std;

/// Every time we can fix a ball of the i colour at the end and fill the former places with other balls
/// Thus we can get the answer for when only k=2.
/// Now when k=3,new color balls are available then put one ball at last place and other ball of this color will be placed other places
///  For every possible answer of color (k=2) ,we can get different ways so count f(i-1)*f(i) and so on.

typedef long long ll;

const int mx=1010;

ll nCr[mx][mx];
const ll mod = 1000000007;

void pre_compute()
{
    nCr[0][0]=1ll;
    for(int i=1;i<mx;i++)
    {
        nCr[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            nCr[i][j]=(nCr[i-1][j]+nCr[i-1][j-1])%mod;
        }
    }
}

int main()

{
    pre_compute();
    int k;
    cin>>k;
    int color[k];
    for(int i=0;i<k;i++) cin>>color[i];
    ll result=1ll;
    ll tota_balls=0ll;
    for(int i=0;i<k;i++)
    {
        tota_balls+=(ll)color[i];
        result*=(nCr[tota_balls-1][color[i]-1]);
        result%=mod;
    }
    cout<<(result%mod)<<endl;
    return 0;
}
