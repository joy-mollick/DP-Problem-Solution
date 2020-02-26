#include<bits/stdc++.h>
using namespace std;

int n, MAX_VAL = 999999999, dp[4096][12][12], A[12], P[12];
 
int min(int a, int b) {
	return (a < b)? a: b;
}
 
int solve(int mask, int first, int second, int count) {
	if (count == n) {
		return 0;
	}
	if (dp[mask][first][second] == -1) {
		int ans = MAX_VAL;
		for (int i = 0; i < n; ++i) {
			if ((mask & (1 << i)) == 0) {
				ans = min(ans, (A[first] ^ A[second] ^ A[i]) * P[count] + solve(mask | (1 << i), i, first, count + 1));
			}
		}
		dp[mask][first][second] = ans;
	}
	return dp[mask][first][second];
}
 
int main() {
	int t, i, j, k, first, second, ans, mask;
	scanf("%d\n", &t);
	while (--t >= 0) {
		scanf("%d\n", &n);
		for (i = 0; i < n; ++i) {
			scanf("%d ", A + i);
		}
		for (i = 0; i < n; ++i) {
			scanf("%d ", P + i);
		}
		for (i = 0; i < (1 << n); ++i) {
			for (j = 0; j < n; ++j) {
				for (k = 0; k < n; ++k) {
					dp[i][j][k] = -1;
				}
			}
		}
		for (first = 0, ans = MAX_VAL; first < n; ++first) {
			for (second = first + 1; second < n; ++second) {
				mask = (1 << first) | (1 << second);
				ans = min(ans, solve(mask, first, second, 2));
				ans = min(ans, solve(mask, second, first, 2));
			}
		}
		printf("%d\n", ans);
	}
}
