
#include<bits/stdc++.h>

using namespace std;

// Classical dp 

typedef  long long ll;
#define inf 1e18

ll dp[101][101][101];
ll cost[101][101];

int main()

{
   int n,m,k;

   cin>>n>>m>>k;

   int colour[n];

   for(int i=1;i<=n;i++) cin>>colour[i];


   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=m;j++)
       {
           cin>>cost[i][j];
       }
   }

   // dp[i][j][k] states that first i trees with beauty j with last coloured by k colour

   for(int i=0;i<=n;i++)
   {
       for(int j=0;j<=k;j++)
       {
           for(int l=0;l<=m;l++)
           {
               dp[i][j][l]=inf;// initially make them all infinity
           }
       }
   }

   //base condition

   if(colour[1]==0)
   {
       for(int i=1;i<=m;i++) dp[1][1][i]=cost[1][i];
   }
   else dp[1][1][colour[1]]=0;// there is no cost for first one if that is set colour

   for(int i=2;i<=n;i++)
   {
       for(int j=1;j<=k;j++)
       {
           if(colour[i]==0)
           {
               for(int K=1;K<=m;K++)
                {
                    // Think new colour is same as before so beauty will be same as j
                  dp[i][j][K]=min(dp[i][j][K],dp[i-1][j][K]+cost[i][K]);

                  for(int K1=1;K1<=m;K1++)
                  {
                      if(K1==K) continue;
                      // Think new colour is not same as before so beauty will be compared to j-1 and colour K1
                      dp[i][j][K]=min(dp[i][j][K],dp[i-1][j-1][K1]+cost[i][K]);
                  }

                }
           }
           else
           {

                    // Think new colour is same as before so beauty will be same as j
                  dp[i][j][colour[i]]=min(dp[i][j][colour[i]],dp[i-1][j][colour[i]]);

                  for(int K1=1;K1<=m;K1++)
                  {
                      if(K1==colour[i]) continue;
                      // Think new colour is not same as before so beauty will be compared to j-1.
                      dp[i][j][colour[i]]=min(dp[i][j][colour[i]],dp[i-1][j-1][K1]);
                  }

           }
       }
   }

   //now iterates through the all colour and think them as last colour

   ll ans=inf;

   for(int i=1;i<=m;i++) ans=min(ans,dp[n][k][i]);

   if(ans==inf) cout<<"-1"<<endl;
   else   cout<<ans<<endl;
}
