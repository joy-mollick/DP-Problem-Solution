/// Time-  0.004s
/// LightOj- 1122 - Digit Count
///  Classical DP 


/// A must do problem 


#include<bits/stdc++.h>

using namespace std;


int main()

{
   int t;
   scanf("%d",&t);
   for(int caso=1;caso<=t;caso++)
   {
       int m,n;
       scanf("%d%d",&m,&n);
       int dp[n+1][m+1];
       int S[m+1];
       memset(dp,0,sizeof(dp));
       /// set of digits
       for(int i=1;i<=m;i++) cin>>S[i];
       /// when ith digit is at S[j] and here length is 1
       /// So, when first position's digit is S[j]
       for(int j=1;j<=m;j++) dp[1][j]=1;

       for(int i=2;i<=n;i++)
       {
           for(int j=1;j<=m;j++)
           {
               for(int k=1;k<=m;k++)
               {
                   if(abs(S[j]-S[k])<=2)
                   {
                       ///when i digits building
                       /// then it comes from i-1 digits when
                       /// last digit was S[j] and now last digit(ith digit) is S[k]
                       /// two adjacent characters hold S[j]-S[k]<=2
                       dp[i][k]+=dp[i-1][j];
                   }
               }
           }
       }
      int res = 0;
      /// taking count ,when last (nth digit) is S[j]
      for(int j=1;j<=m;j++) res+=dp[n][j];
      printf("Case %d: %d\n", caso, res);
   }
   return 0;
}
