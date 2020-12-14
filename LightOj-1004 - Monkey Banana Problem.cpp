
/// Time-0.155s
/// 1004 - Monkey Banana Problem
/// Classical DP -LOJ

#include<bits/stdc++.h>

using namespace std;

long long ban[500][500],dp[500][500];

/// dp[i][j] states the maximum bananas caught by monkey at that state 

int main()

{
    int T,N;
    cin>>T;
    int caso=0;

    while(T--)
    {
        cin>>N;
        caso++;
        memset(ban,0,sizeof(ban));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<=i;j++)
            {
                cin>>ban[i][j];
            }
        }

        for(int i=N,k=N-1;i<2*N-1;i++,k--)
        {
            for(int j=0;j<k;j++)
            {
                cin>>ban[i][j];
            }
        }
        dp[0][0]=ban[0][0];
        /// initial state-same as given


        /// it is for up to Nth row

         for(int i=0;i<N-1;i++)
        {
            for(int j=0;j<=i;j++)
            {
                dp[i+1][j]=max(dp[i+1][j],ban[i+1][j]+dp[i][j]);
                dp[i+1][j+1]=max(dp[i+1][j+1],ban[i+1][j+1]+dp[i][j]);
            }
        }

        /// it is for lower part

        for(int i=N,k=N-1;i<2*N-1;i++,k--)
        {
            for(int j=0;j<k;j++)
            {
                int mx_from_up=max(dp[i-1][j],dp[i-1][j+1]);
                /// current position 
                dp[i][j]=ban[i][j]+mx_from_up;
            }
        }

        cout<<"Case "<<caso<<": "<<dp[2*N-2][0]<<endl;
    }

    return 0;
}
