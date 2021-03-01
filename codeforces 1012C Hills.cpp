
/// codeforces 1012C Hills
/// dp problem
/// Nice problem + Classical one!!


#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int maxx=300001;

const int N = 5005;
int a[N];
/// it is better for fast iteration we should take dp like dp[2][N/2][N]
/// But in this constraint ,it is ok
int dp[N][N/2][2];

int main() {
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    ///cout<<dp[1][0][0]<<endl;
    /// extreme base case
    dp[1][0][0] = dp[1][1][1] = dp[0][0][0] =0;
    for(int i = 2 ; i <= n ; i++){
            /// base case every time
            /// for 1 to i intervals there is no need to cost to choose 0 mountain
        dp[i][0][0] = 0;
        for(int j = 1 ; j <= (i+1)/2 ; j++)
        {
            /// we will assume that we will not build house at ith mountain
            /// so , we will take value not putting house at i-1 th mountain
            /// and assuming house at i-1 th mountain so, a[i] should be less than a[i-1]
            /// a[i]-a[i-1]+1 should be cost
            dp[i][j][0] = min(dp[i-1][j][0], dp[i-1][j][1]+max(0, a[i]-a[i-1]+1));

            /// we will assume that we will put house at ith mountain
            /// so ,there can be two cases that at (i-2)th position there is a house , so at ith and i-2th there are houses
            /// so a[i-1] should be less than both i.e. less than the minimum of a[i] & a[i-2]
            /// another case is there is no house at i-2th so, only assuming i-1 should be less than current a[i]
            /// that's all
            dp[i][j][1] = min(dp[i-2][j-1][0]+max(0, a[i-1]-a[i]+1), dp[i-2][j-1][1]+max(0, a[i-1]-min(a[i-2], a[i])+1));
        }
    }
    for(int i = 1 ; i <= (n+1)/2 ; i++){
            /// so for 1 to n interval taking i houses over mountains,if we think at ith mountain there is a house or at ith mountain there is no house then.
        cout << min(dp[n][i][0], dp[n][i][1]) << ' ';
    }
    return 0;
}
