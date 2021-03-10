/// codeforces Codeforces 1114D Flood Fill
/// Category :  DP ( O(n^2) )
/// Fantastic One


/// here we will find the longest non-increasing segment with ending at 1
/// but to find it we have to find the non-increasing with ending 2 also
/// so we will keep two states for ending purpose
/// dp[i][j][0] states for longest non-increasing subsequence in the interval ending at 1
/// dp[i][j][1] states for longest non-increasing subsequence in interval ending at 2

#include <bits\stdc++.h>

using namespace std;

const int N = 3001;

int dp[N][N][2];
int one_before[N];
int two_after[N];
int a[N];

// transfer equation

///dp[i][j][1] = dp[i][j-1][1] + (a[j]==2);
///dp[i][j][0] = max(dp[i][j-1][0], dp[i][j-1][1]) + (a[j]==1)

int main()
{
     int n, t;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)  {
        scanf("%d", &a[i]);
        one_before[i] += one_before[i-1] + (a[i]==1);
    }
    for(int i = n; i >= 1; i--)
        two_after[i] += two_after[i+1] + (a[i]==2);

    int ans = INT_MIN;
    for(int i = 1; i <= n; i++) {
        int ans1=0, ans2=0;
        for(int j = i; j <= n; j++) {
            dp[i][j][1] = dp[i][j-1][1] + (a[j]==2);
            dp[i][j][0] = max(dp[i][j-1][0], dp[i][j-1][1]) + (a[j]==1);
            ans = max(ans, dp[i][j][1] + one_before[i-1]+two_after[j+1]);
            ans = max(ans, dp[i][j][0] + one_before[i-1]+two_after[j+1]);
        }
    }
    printf("%d\n", ans);

    return 0;
}
