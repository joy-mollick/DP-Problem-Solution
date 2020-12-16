
///   Time- 0.004s
///    1025 - The Specials Menu 
///  Classical dp + palindrome problem

#include<bits/stdc++.h>

using namespace std;

int main()

{
    int T,n,w,k,x;
    cin>>T;
    int caso=0;
    string s;
    while(T--)

    {
        cin>>s;
        caso++;
        n=s.size();
        long long dp[n+1][n+1];
        memset(dp,0,sizeof(dp));

        /// initialization as a single character is a palindrome of one length
        for(int i=0;i<n;i++) dp[i][i]=1;

        /// check subsequence of Length n
        /// dp[i][j] states that the number of palindrome subsequence between indices i and j

        for(int len=2;len<=n;len++)
        {
            for(int i=0;i<n;i++)
            {
                int j=len+i-1;

                if(s[i]==s[j])
                {
                    dp[i][j]=dp[i][j-1]+dp[i+1][j]+1;
                }

                else
                {
                    dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
                }
            }
        }

        printf("Case %d: %lld\n", caso,dp[0][n-1]);
    }

    return 0;
}
