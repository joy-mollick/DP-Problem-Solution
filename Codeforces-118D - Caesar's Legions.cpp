#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const ll mod=100000000;

int main()

{
   int n1,n2,k1,k2;
   cin>>n1>>n2>>k1>>k2;
   ll dp[n1+1][n2+1][k1+1][k2+1];
   memset(dp,0,sizeof(dp));
   for(int i=0;i<=n1;i++)
   {
       for(int j=0;j<=n2;j++)
       {
           for(int k=0;k<=k1;k++)
           {
               for(int f=0;f<=k2;f++)
               {
                   ll ans=0ll;
                   if(i==0&&j==0) {ans=1ll;}
                   else{
                        ans=0ll;
                    if(k>0&&i>0) {ans+=dp[i-1][j][k-1][k2]%mod;}
                    if(j>0&&f>0) {ans+=dp[i][j-1][k1][f-1]%mod;}
                   }
                   dp[i][j][k][f]=ans%mod;
               }
           }
       }
   }
   cout<<dp[n1][n2][k1][k2]<<endl;
    return 0;
}
