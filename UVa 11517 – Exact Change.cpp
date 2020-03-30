#include<bits/stdc++.h>

using namespace std;

int dp[20001];

int main()

{
        int tc;
        cin>>tc;
        while(tc--)
        {
         int amount;
         cin>>amount;
         int n,val;
         cin>>n;
         vector<int>coins;
         for(int i=0;i<n;i++)
         {
             cin>>val;
             coins.push_back(val);
         }
         for(int i=0;i<=20000;i++)
         {
             dp[i]=1000000;
         }
         dp[0]=0;
        for(int i=0;i<coins.size();i++)
        {
            int val=coins[i];
            for(int j=amount;j>=0;j--)
            {
                    dp[j+val]=min(dp[j]+1,dp[j+val]);/// howmany minimum coins can be used to make i ,for dp[i]
            }
        }
        /// precomputation ends
        for(int i=amount;;i++)
        {
            if(dp[i]<1000000&&dp[i])
            {
                cout<<i<<" "<<dp[i]<<endl;
                break;
            }
        }

        }
    return 0;
}
