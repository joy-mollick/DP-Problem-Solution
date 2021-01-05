
/// Codeforces 255C - Almost Arithmetical Progression

/// Classical dp 


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    int val[n+1];
    memset(val,0,sizeof(val));

    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));

    /// dp[i][j] states the longest subsequence where zigzag sequence will be composed of arr[i] arr[j] arr[i] arr[j] arr[i] like this

    int ans=0;
    for(int i=1;i<=n;i++) cin>>val[i];

    for(int i=1;i<=n;i++)
    {
        /// it will keep the index which is equal to arr[i]
        int last=0;
        for(int j=0;j<i;j++)
        {
            /// dp[j][last] that means how much length can be when starting element is i :) as last = i .
            /// By putting i at end , new subsequence will be extended to prev + one
            dp[i][j]=max(dp[i][j],dp[j][last]+1);
            if(val[i]==val[j]) last=j;
            ans=max(ans,dp[i][j]);
        }
    }

    cout<<ans<<endl;

    return 0;
}
