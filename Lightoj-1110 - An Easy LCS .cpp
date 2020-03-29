
#include<bits/stdc++.h>

using namespace std;

/// It can be done by bactracking also for printing lcs

int main()
{
    int tc;
    cin>>tc;
    int caso=0;
    while(tc--)
    {
        caso++;
        string a,b;
        cin>>a;
        cin>>b;
        int n=a.length();
        int m=b.length();
        int dp[n+1][m+1];
        string ans[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++)
        {
            ans[i][0]="";/// base case
        }
        for(int i=0;i<=m;i++)
        {
            ans[0][i]="";/// base case
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    ans[i][j]=ans[i-1][j-1]+b[j-1];
                }
                else if(dp[i-1][j]==dp[i][j-1])
                {
                    dp[i][j]=dp[i-1][j];
                    ans[i][j]=min(ans[i-1][j],ans[i][j-1]);///here more than one lcs exists, take minimum one
                }
                else if(dp[i-1][j]>dp[i][j-1])
                {
                    dp[i][j]=dp[i-1][j];
                    ans[i][j]=ans[i-1][j];
                }
                else if(dp[i-1][j]<dp[i][j-1])
                {
                    dp[i][j]=dp[i][j-1];
                    ans[i][j]=ans[i][j-1];
                }
            }
        }
        printf("Case %d: ",caso);
        if(dp[n][m]==0) cout<<":("<<'\n';
        else cout<<ans[n][m]<<'\n';
    }
    return 0;
}
