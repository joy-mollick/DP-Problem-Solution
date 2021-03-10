

/// codeforces 958C2 Encryption (medium)
/// Category : Classical DP
/// Very Nice one 

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mx = 20001;
ll sum[mx];
ll dp[mx][51];

int main()

{
    int n,k,p,x;
    
    cin>>n>>k>>p;
    
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        sum[i]=(sum[i-1]+x)%p;
    }
    
    for(int i=0;i<=p;i++)
    {
        for(int j=0;j<=k;j++)
        {
            dp[i][j]=-(1<<30);
        }
    }
    
    /// dp[i][j] states the maximum score with where sum is i and j segment 
    /// dp[i][j] denotes that the substring of length i is divided into the optimal solution of segment j.
    /// transition will be like dp[i][j] = max(dp[i]][j], dp[i][j-1]+(sum[r]-sum[l]+p)\%p)
    /// but it will cause time-limit.O(n^2) 
    /// So ,it is greedy to select dp[pre[i]][j] as i can be up to range 20000
    /// but pre[i] is prefix sum and nothing but modulo by 50 
    /// So it will not cross 50 
    /// this is greedy 
    
    dp[0][0]=0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            for(int mod=0;mod<=p;mod++)
            {
                dp[sum[i]][j]=max(dp[sum[i]][j],dp[mod][j-1]+(sum[i]-mod+p)%p);
            }
        }
    }
    
    cout<<dp[sum[n]][k]<<endl;
    
    return 0;
}
