#include<bits/stdc++.h>
using namespace std;

long int mod=1e9+7;

typedef long long int ll;

ll val[20][20];
int main()
{

   int n,m,k,x,y;
   ll K;
    cin>>n>>m>>k;
    ll arr[n];
    ll dp[(1<<n)][n];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++) cin>>arr[i];

    for(int i=0;i<k;i++)
    {
            cin>>x>>y>>K;
            x--;
            y--;
            val[x][y]=K;
    }
    ll ans=0;
    for(int i=0;i<n;i++) dp[1<<i][i]=arr[i];// take every element

    for(int mask=0;mask<(1<<n);mask++)
    {
        for(int i=0;i<n;i++){

                if(!(mask&(1<<i))) continue; // ith bit is not set here .So, we can't take it with associated jth element which is on in mask

        for(int j=0;j<n;j++)
        {
            if(i==j) continue;

            if(!(mask & (1<<j))) // j bit on we can take this and make sum with ith elemnt which is on in the mask
            {
               int nw_mask_wth_jth_on= (mask|(1<<j));//mask without ith bit on,then we will take this and make the ith on
               dp[nw_mask_wth_jth_on][j]=max(dp[nw_mask_wth_jth_on][j],dp[mask][i]+arr[j]+val[i][j]);
               //cout<<" "<<j<<" "<<dp[nw_mask_wth_jth_on][j]<<endl;
            }

        }
    }

    }

    for(int i=0;i<(1<<n);i++)
    {
        int tot=__builtin_popcount(i);
        if(tot==m){
        for(int j=0;j<n;j++)
        {
            ans=max(ans,dp[i][j]);
        }
        }
    }
    cout<<ans<<endl;
   return 0;
}
