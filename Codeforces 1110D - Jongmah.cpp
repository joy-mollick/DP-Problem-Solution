
/// Codeforces 1110D - Jongmah
/// dp 


/// dp[i][j][k] states that the number of such triplets (i.e. x,x,x or x+1,x+2,x+3 ) assuming numbers from 1 to i range
/// where the amount of (i-1,i,i+1) triplets is j and amount of (i,i+1,i+2) triplets is k




#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000010;

int a[maxn], cnt[maxn];

int dp[maxn][3][3];

int main ()

{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
    {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}

	memset(dp, -0x3f, sizeof(dp));

	dp[0][0][0] = 0;
	for (int i = 0; i <= m + 1; i++) {
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++) {
				if(dp[i][j][k]<0) continue;

				/// because already dp[i][j][k] assumed
				/// j (i+1) s for triplets (i - 1, i, i + 1)
				/// and k (i+1) s for triplets (i, i + 1, i + 2)
				/// So , subtract (i+j) amount from count of (i+1)

				int now = cnt[i + 1] - j - k;

				/// Now rest of  will be added for triplets (i+1 , i+1, i+1)
				/// and 2 or 1 (i+1) will be remained
				/// these will be taken into account as for triplets (i+1,i+2,i+3)

				for (int t = 0; t < 3 && t <= now; t++) {
					dp[i + 1][k][t] = max(dp[i + 1][k][t], dp[i][j][k] + (now - t) / 3 + t);
				}
			}
	}
	printf("%d\n", dp[m + 1][0][0]);
	return 0;
}
