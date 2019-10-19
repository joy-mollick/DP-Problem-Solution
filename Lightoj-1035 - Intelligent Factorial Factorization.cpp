#include <bits/stdc++.h>

 using namespace std;

 int dp[101][101];

 void pre_cal(int n)
 {
     int x=n;
     int cont=0;
     while(n%2==0)
     {
         n=n>>1;
         cont++;
     }
     if(cont) {dp[x][2]=cont;}
     for(int i=3;i*i<=n;i=i+2)
     {
         cont=0;
         bool ok=false;
         while(n%i==0)
         {
             ok=true;
             n=n/i;
             cont++;
         }
         if(ok) {dp[x][i]=cont;}
     }
     if(n>1) {dp[x][n]=1;}
     //return;
 }

 int main()

 {
     memset(dp,0,sizeof(dp));
     for(int i=2;i<=100;i++){
        pre_cal(i);
        }
        for(int i=2;i<=100;i++)
        {
            for(int j=2;j<=i;j++)
            {
                dp[i][j]+=dp[i-1][j];
            }
        }
     int tc,n,s=1;
     scanf("%d",&tc);
     while(tc--)
     {
     scanf("%d",&n);
     printf("Case %d: ",s);
     s++;
     printf("%d = ",n);
     int frst=0;
     for(int i=2;i<=n;i++)
     {
         if(dp[n][i]>0)
         {
             if(frst)
             {
                 printf(" * %d (%d)",i,dp[n][i]);
             }
             else
             {
                 printf("%d (%d)",i,dp[n][i]);
                 frst=1;
             }
         }
     }
     puts("");
     }
 }
