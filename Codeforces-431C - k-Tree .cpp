
/// Codeforces - C.k-Tree.
/// Category - Dp (coin change)

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod=1000000007;

const int mx=101;

ll tot[mx];
ll xtra[mx];

int main()

{
    ll n,k,d;
    cin>>n>>k>>d;

    for(int i=1;i<=k;i++)
    {
        /// i<=k obviously
        tot[i]=1ll;
        /// i<d ,when
        if(i<d) xtra[i]=1ll;
    }

    tot[0]=0;
    xtra[0]=0;

    /// how many ways we can build n by summing j
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            /// ignore this
            if(i<j) continue;
            tot[i]=(tot[i]+tot[i-j])%mod;
        }
    }

    ///how many ways we can build n by summing j,where j<d is true for all j
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            /// ignore this
            if(i<j) continue;
            /// j is less than d.
            if(j<d) xtra[i]=(xtra[i]+xtra[i-j])%mod;
        }
    }

    /// now,we can get the answer where number of ways
    /// we can build n,where there at least one value is at least equal to d.
    ll ans=(tot[n]-xtra[n]+mod)%mod;
    cout<<ans<<endl;

    return 0;
}
