
/// Codeforces:  474D - Flowers .
/// Category: Dp + Combinatorics.


#include<bits/stdc++.h>

using namespace std;

const int mx=100001;

const int mod=1e9+7;

int dp[mx];
int pref_dp[mx];

int main()

{
    int tc,k,a,b;
    cin>>tc>>k;
    /// base case.
    /// pre-caculate
    dp[0]=1;
    for(int i=1;i<mx;i++)
    {
        /// two flower,red and white flower
        /// white in the group of k.
        dp[i]=dp[i-1];///red flower can increase ,no fact about group size
        if(i>=k)
        {
            dp[i]+=dp[i-k];
        }
        dp[i]%=mod;
        pref_dp[i]=dp[i];
    }
    /// making prefix summation of dp.
    pref_dp[0]=0;
    for(int i=1;i<mx;i++)
    {
        pref_dp[i]+=pref_dp[i-1];
        pref_dp[i]%=mod;
    }

    while(tc--)
    {
        cin>>a>>b;
        cout<<((pref_dp[b]-pref_dp[a-1])%mod+mod)%mod<<"\n";
    }

   return 0;
}
