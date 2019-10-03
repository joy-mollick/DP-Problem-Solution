#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int n, m, k;

LL dp[5050][5050], sum[5050], x[5050];

int main(){
    scanf( "%d%d%d", &n, &m, &k );
    for ( int i = 1; i <= n; i ++ ) {
        scanf( "%I64d", &x[i] );
        sum[i] = sum[i - 1] + x[i];
    }

    for ( int i = m; i <= n; i ++ ) {
        for ( int j = 1; j <= k; j ++ ) {
            dp[i][j] = max( dp[i - 1][j], dp[i][j] );
            dp[i][j] = max( dp[i - m][j - 1] + sum[i] - sum[i - m], dp[i][j] );
        }
    }

    cout <<dp[n][k]<<endl;

    return 0;
}
