#include<bits/stdc++.h>

using namespace std;

const long long mod = 100000007;

/// there are many recursion ways to solve this ,but I like dp by bottom-up approach 
/// bottom- up approach 

int main()

{
    int tc;
    scanf("%d",&tc);
    int caso=0;
    while(tc--)
    {
        caso++;
        int n,k;
        scanf("%d%d",&n,&k);
        int arr[n];
        int amount[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        for(int j=0;j<n;j++)
        {
            scanf("%d",&amount[j]);
        }
        long long dp[n+1][k+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<n;i++)/// we can use n types of coins
        {
            for(int j=0;j<=k;j++)/// build k , check by making sub-sum
            {
                for(int times=0;times<=amount[i];times++)
                {
                    if(times*arr[i]<=j)/// is it possible to make j with times*arr[i]?
                    {
                        dp[i+1][j]=dp[i+1][j]+dp[i][j-(times*arr[i])]%mod;
                    }
                }
            }
        }
        printf("Case %d: %lld\n",caso,dp[n][k]);/// by using n types of coins how many ways to make k
    }
    return 0;
}
