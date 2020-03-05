#include<bits/stdc++.h>

using namespace std;

// dp
#define mxn 50002

int dp[mxn][7];// n can be maximum 5

int main()
{
	ios_base::sync_with_stdio(false);
	int m,n;
	cin>>m>>n;
	int t[m+1][n+1];

	for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>t[i][j];
        }
    }

    // dp[i][j] states that how much time needed to work ith paint by jth worker

    for(int j=1;j<=n;j++)
    {
        int free_at_time=0;// initialize it with zero
        for(int i=1;i<=m;i++)
        {
            int start_time=max(free_at_time,dp[i][j-1]);// it will store the time which j-1th painter  will work for till i paint ,after that time jth painter will do that ith paint
            dp[i][j]=start_time+t[i][j];// keep  time(free time) needed stored to do ith paint and add t[i][j] to this
            free_at_time=dp[i][j];// now after doing ith paint jth painter will be free i mean after dp[i][j] time ith paint can be done by jth painter
        }

    }

    for(int i=1;i<=m;i++) cout<<dp[i][n]<<" ";// time needed to work ith paint by nth painter
}
