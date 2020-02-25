#include<bits/stdc++.h>
using namespace std;

long int mod=1e9+7;

long long  dp[1<<16][16];

int main()
{
    int n;
    cin>>n;
    long long arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    for(int mask=0;mask<(1<<n);mask++)
    {
        for(int i=0;i<n;i++){

                if(!mask&(1<<i)) continue; // ith bit is not set here .So, we can't take its gcd with jth element which is on in mask

        for(int j=0;j<n;j++)
        {
            if(i==j) continue;

            if((mask & (1<<j))) // j bit on we can take this and make gcd with ith elemnt which is on in the mask
            {
               int nw_mask_wth_ith_of= mask&(~(1<<i));//mask without ith bit on,then we will take this and make the ith on
               dp[mask][i]=max(dp[mask][i],dp[nw_mask_wth_ith_of][j]+__gcd(arr[j],arr[i]));
            }

        }

        }
    }

    long long mx=-1;
    for(int j=0;j<n;j++)
    {
        mx=max(mx,dp[(1<<n)-1][j]);
        //cout<<dp[(1<<n)-1][j]<<endl;
    }
    cout<<mx<<'\n';
   return 0;
}
