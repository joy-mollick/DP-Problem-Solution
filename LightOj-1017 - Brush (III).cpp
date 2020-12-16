
///   Time- 0.006s
///   1017 - Brush (III) 
///  Classical dp + sort

#include<bits/stdc++.h>

using namespace std;

int main()

{
    int T,n,w,k,x;
    cin>>T;
    int caso=0;
    while(T--)

    {

        caso++;
        cin>>n>>w>>k;
        int y[n+1];
        int cover[n+1];
        int dp[n+1][k+1];
        memset(dp,0,sizeof(dp));
        memset(cover,0,sizeof(cover));

        for(int i=1;i<=n;i++) cin>>x>>y[i];

        sort(y+1,y+1+n);
        /// first we can find out if we touch particular point how many ranges can be covered ?

        for(int i=1;i<=n;i++)
        {
            for(int j=i;j>=1;j--)
            {
                if(y[i]-y[j]<=w) cover[i]++;
                else break;
            }
        }

        /// now if we touch a point some ranges of its points will be covered for their ranges so, it is optimal to choose maximum k points
        /// Here is the fact ,dynamic programming.

         for(int i=1;i<=n;i++)
         {
             for(int j=1;j<=k;j++)
             {
                 if(i==cover[i])
                 {
                     dp[i][j]=cover[i];
                 }
                 /// i>cover[i]
                 else
                 {
                     dp[i][j]=max(dp[i-1][j],dp[i-cover[i]][j-1]+cover[i]);
                 }
             }
         }
        /// so,after full iteration -> at most k moves upon n points result will be dp[n][k]
        printf("Case %d: %d\n", caso,dp[n][k]);
    }

    return 0;
}
