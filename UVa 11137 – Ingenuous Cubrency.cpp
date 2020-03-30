#include<bits/stdc++.h>

using namespace std;

int main()

{
        vector<int>coins;
        for(int i=1;i<=21;i++)
        {
            coins.push_back(i*i*i);
        }
        int target=10000;
        long long dp[target+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<coins.size();i++)
        {
            int val=coins[i];
            for(int j=val;j<=target;j++)
            {
                if(val<=j)
                {
                    dp[j]+=dp[j-val];
                }
            }
        }
        /// precomputation ends
        int n;
        while(cin>>n)
        {
            cout<<dp[n]<<endl;
        }
    return 0;
}
