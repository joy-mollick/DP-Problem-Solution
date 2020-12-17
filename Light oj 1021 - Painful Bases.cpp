
/// Time-0.162s
/// Light OJ -> 1021 - Painful Bases

/// Classical Bitmask dp (medium-hard)
/// Very Nice One
/// How many numbers of the same digits of N num which are divisible by M

/// So, here one thing is that the number of digits can be maximum 18.
/// So, by enumeration we can check whatever we need ?
/// dp[i][j]= nn ,i is mask .states that the numbers which are composed of the digits according to mask of i from the real number having modulo by M (here j) are nn.
/// From this process ,dp[(1<<len)-1][0] states that all permutations of all digits of number having modulo (%M) =0 .

/// Here is another thing is that ,base is variable
/// So , when we do modulo we will multiply previous modulo by base

#include<bits/stdc++.h>

#define LL long long

using namespace std;

LL dp[1 << 16][20];
char n[20];

int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
    int l, m, len,base;
    memset(dp,0,sizeof(dp));
    cin >> base >> m >>n;
    l = strlen(n), len = (1 << l);

    for(int i=0;i<l;i++)
    {
        n[i]=(n[i]>='A')?n[i]-'A'+10:n[i]-'0';
    }
    /// when the mask is 0 ,then this mask express zero which is divisible by any number say m
    /// So, dp[0][0] = 1 , base case
    dp[0][0] = 1;

    for(int i = 0;i < len;i ++)
    {
        for(int j = 0;j < l;j ++){

            /// if j bit is on ,then neglect this
            if(i & (1 << j)) continue;

                for(int k = 0;k < m;k ++)
                {

                    dp[i|(1<<j)][(k*base+n[j])%m] += dp[i][k];
                }
        }
    }
    printf("Case %d: ",i);
    cout << dp[len-1][0]<< endl;
    }
}
