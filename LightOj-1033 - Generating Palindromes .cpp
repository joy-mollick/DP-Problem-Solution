#include<bits/stdc++.h>

using namespace std;

long long mod=100000007;

int main()

{
    int tc;
    cin>>tc;
    int caso=0;
    while(tc--)
    {
        caso++;
        string s;
        cin>>s;
        string s1=s;
        reverse(s1.begin(),s1.end());
        int n=s.length();
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0||j==0) dp[i][j]=0;

                else if(s[i-1]==s1[j-1])
                {
                    dp[i][j]=(dp[i-1][j-1]+1);
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        printf("Case %d: %d\n",caso,n-dp[n][n]);
    }
    return 0;
}
