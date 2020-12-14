
/// Time-0.194s
///  1011 - Marriage Ceremonies 
///  Bitmask DP -LOJ 

#include<bits/stdc++.h>

using namespace std;

/// Problem , basic N job and N workers assignment problem

const int MAX =31;


int main()

{
    int T,n;
    cin>>T;
    int caso=0;

    while(T--)
    {
    caso++;
    cin>>n;
    int dp[1<<n];
    int m[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>m[i][j];
        }
    }

    dp[0]=0;
    memset(dp,0,sizeof(dp));
/// from mask ,count bit means such person have assigned to that man choose maximum best option
/// dp[11111...] states all man assign by choosing best probability from all area

        for (int mask = 0; mask < (1<<n); mask++)
            {
            for (int j = 0; j < n; j++)
            {
                if ((mask & (1 << j)) == 0)
                {
                    /// o to k-1 ,k people have been assigned ,now for rest of all.
                    int k=__builtin_popcount(mask);
                   dp[mask|(1 << j)] =max(dp[mask|(1 << j)],dp[mask]+m[k][j]);
                }
            }
        }

        cout<<"Case "<<caso<<": "<<dp[(1<<n)-1]<<endl;

    }

    return 0;
}
