
/// Codeforces- Div1 295A - Greg and Array.
/// Category: greedy + data structure (medium).

/// Time complexity -O(n).

#include<bits/stdc++.h>

using namespace std;

const int mx=100001;

typedef long long ll;

struct operation
{
   int left;
   int right;
   ll val;
   ll cont=0ll;
};

operation op[mx];
ll arr[mx];
ll xtra[mx];

int main()

{
    ll n,m,k,l,r;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=m;i++)
    {
        cin>>op[i].left;
        cin>>op[i].right;
        cin>>op[i].val;
    }
    while(k--)
    {
        cin>>l>>r;
        op[l].cont++;
        op[r+1].cont--;
    }
    /// calculating number of operations used by queries
    for(int i=2;i<=m;i++)
    {
        op[i].cont+=op[i-1].cont;
    }

    for(int i=1;i<=m;i++)
    {
        ll l=op[i].left;
        ll r=op[i].right;
        ll val=op[i].val;
        ll conts=op[i].cont;
        xtra[l]+=(conts*val);
        xtra[r+1]-=(conts*val);
    }
    for(int i=1;i<=n;i++)
    {
        xtra[i]+=xtra[i-1];
    }
    for(int j=1;j<=n;j++) cout<<(unsigned long long)(arr[j]+xtra[j])<<" ";
    cout<<endl;

    return 0;
}
