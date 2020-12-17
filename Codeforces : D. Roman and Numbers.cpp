
/// Time-1028ms
/// D. Roman and Numbers.

/// Classical Bitmask dp (medium-hard)
/// Very Nice One 
/// How many numbers of the same digits of N num which are divisible by M 

/// So, here one thing is that the number of digits can be maximum 18.
/// So, by enumeration we can check whatever we need ? 
/// dp[i][j]= nn ,i is mask .states that the numbers which are composed of the digits according to mask of i from the real number having modulo by M (here j) are nn.
/// From this process ,dp[(1<<len)-1][0] states that all permutations of all digits of number having modulo (%M) =0 . 

#include<bits/stdc++.h>

#define LL long long

using namespace std;

const int MAXN = 18;

const int MAXM = 101;

LL dp[1 << MAXN][MAXM], d = 1;

int main()
{
    int l, m, len, c[10] = {0};
    char n[20];
    cin >> n >> m;
    l = strlen(n), len = (1 << l);
    /// when the mask is 0 ,then this mask express zero which is divisible by any number say m 
    /// So, dp[0][0] = 1 , base case 
    dp[0][0] = 1;
    for(int i = 0;i < l;i ++) d *= ++c[n[i] -= '0'];
    for(int i = 0;i < len;i ++){
        for(int j = 0;j < l;j ++){
            
            /// if j bit is on ,then neglect this 
            if(i & (1 << j)) continue;
        
        /// zero can't be as leading digit
            if(i || n[j]){
                for(int k = 0;k < m;k ++)
                {
                    
                    dp[i|(1<<j)][(k*10+n[j])%m] += dp[i][k];
                }
            }
        }
    }
    /// total / duplicate
    cout << dp[len-1][0]/d << endl;
}
