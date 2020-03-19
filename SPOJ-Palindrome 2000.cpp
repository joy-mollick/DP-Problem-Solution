#include<bits/stdc++.h>

using namespace std;

/// Variation of LCS
typedef unsigned long long ll;



int main()

{
    int t;
    cin>>t;
        string s,s1;
        cin>>s;
        s1=s;
        reverse(s1.begin(),s1.end());
        int n=s.size();
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                }
                else if(s[i-1]==s1[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int pal_lngth=dp[n][n];
        int inser=n-pal_lngth;
        cout<<inser<<endl;
    return 0;
}
