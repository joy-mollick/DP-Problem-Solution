#include<bits/stdc++.h>

using namespace std;

// dp

//    |
// ---. (i,j) so first make dp with from (1,1) to any (i,j) so , a position can be made with max(i,j-1 & i-1,j) as (1,1) is fixed we have to start from (1,1)


// (i,j).----   here we will find maximum to reach to (n,m) from any (i,j) ,as (n,m) is fixed so we have think inversely we will think we reach any (i,j) from (n,m) so in that pattern a position max can be made with max(i+1,j & i,j-1) ,
//      |


//      |
// (i,j).---  here we will go from (1,m) to any (i,j) so , we can make a position max with compare max( i-1,j & i,j+1 )


//  ---.(i,j) here we will go from any (i,j) to (1,n)  so here (1,n) is fixed we can think inversely that we have to come from (1,n) to any (i,j) so at any position max can be made with max(i,j-1 & i+1,j)
//     |


// Now here one observation can be found that they can meet at one cell only one possible moves either one goes right another one comes down
// Now in this move there will two options because any one can make start with first move
// So take two possible max cost and compare them for all i,j

// First Way

// dp[1][i][j - 1] + dp[3][i + 1][j] + dp[2][i - 1][j] + dp[4][i][j + 1]


// Second Way

//dp[1][i - 1][j] + dp[3][i][j - 1] + dp[2][i][j + 1] + dp[4][i + 1][j]
#define MAXN 1010

int n, m;
long long a[MAXN][MAXN], dp[5][MAXN][MAXN],ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[1][i][j] = a[i][j] + max(dp[1][i - 1][j], dp[1][i][j - 1]);
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 1; j--)
			dp[2][i][j] = a[i][j] + max(dp[2][i - 1][j], dp[2][i][j + 1]);
	for (int i = n; i >= 1; i--)
		for (int j = 1; j <= m; j++)
			dp[3][i][j] = a[i][j] + max(dp[3][i + 1][j], dp[3][i][j - 1]);
	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--)
			dp[4][i][j] = a[i][j] + max(dp[4][i + 1][j], dp[4][i][j + 1]);
	for (int i = 2; i <= n - 1; i++)
		for (int j = 2; j <= m - 1; j++)
		{
			long long temp;
			temp = dp[1][i][j - 1] + dp[3][i + 1][j] + dp[2][i - 1][j] + dp[4][i][j + 1];
			temp = max(temp, dp[1][i - 1][j] + dp[3][i][j - 1] + dp[2][i][j + 1] + dp[4][i + 1][j]);
			ans = max(ans, temp);
		}
	cout << ans << endl;
}
