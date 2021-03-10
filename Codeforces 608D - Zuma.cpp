
/// Codeforces 608D - Zuma
/// Category : Classical DP
/// Very Fantastic One


/// dp[i][j] states the minimum operations to destroy all gemstones 
/// if s[i]=s[j] , then it is easy to see that dp[i][j]=dp[i+1][j-1]
/// else we will try for segments k (i<=k<j) ,then dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]) , 


#include<bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int n;
int a[505];
int dp[505][505];

int main()
{
    scanf("%d",&n);
    
    memset(dp,INF,sizeof(dp));
    
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]),dp[i][i]=1;
    }
        
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            
            if(a[i]==a[j])
            {
                if(len==2)
                    dp[i][j]=1;
                else
                    dp[i][j]=dp[i+1][j-1];
            }
            
            /// traversing over i to j 
            for(int k=i;k<j;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}

