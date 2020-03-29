#include<bits/stdc++.h>

using namespace std;


int main()

{
    int tc;
    scanf("%d",&tc);
    int caso=0;
    while(tc--)
    {
        caso++;
        int n,m;
        scanf("%d%d",&n,&m);
        int arr[n];
        int amount[n];
        int num_of_coin_of_type_i_used[m+1];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        for(int j=0;j<n;j++)
        {
            scanf("%d",&amount[j]);
        }
        bool dp[m+1];
        for(int i=0;i<=m;i++)
        {
            num_of_coin_of_type_i_used[i]=0;
            dp[i]=false;
        }
        dp[0]=true;
        for(int i=0;i<n;i++)/// we can use n types of coins
        {
            int val=arr[i];
            for(int j=val;j<=m;j++)/// build j , check by making sub-sum
            {
               if(dp[j-val]&&dp[j]!=1)/// j has not been made still and we can make j-val ,so proceed
               {
                   if(num_of_coin_of_type_i_used[j-val]+1<=amount[i])
                   {
                       dp[j]=true;
                       num_of_coin_of_type_i_used[j]=num_of_coin_of_type_i_used[j-val]+1;/// keep track of using
                   }
               }
            }
            for(int i=0;i<=m;i++)
        {
            num_of_coin_of_type_i_used[i]=0;/// every times it keeps track of amount of using of i type coins
        }

        }
        int ans=0;
        for(int i=1;i<=m;i++) ans=ans+dp[i];
        printf("Case %d: %d\n",caso,ans);/// by using n types of coins how many ways to make k
    }
    return 0;
}
