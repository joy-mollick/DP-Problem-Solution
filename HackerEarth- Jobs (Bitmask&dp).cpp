#include<bits/stdc++.h>
using namespace std;

long int mod=1e9+7;

double dp[1<<20];

int main()
{

    int n;
    cin>>n;
    double ithperson_probability_at_jth_area[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>ithperson_probability_at_jth_area[i][j];
            ithperson_probability_at_jth_area[i][j]=ithperson_probability_at_jth_area[i][j]/100.0;
        }
    }
    dp[0]=1.0;

    // from mask ,count bit means such person have assigned to area by j choose maximum best option
    // dp[11111...] states all man assign by choosing best probability from all area
        for (int mask = 0; mask < (1<<n); mask++) {
            for (int j = 0; j < n; j++) {
                if ((mask & (1 << j)) == 0) {
                        int tot=__builtin_popcount(mask);
                    dp[mask | (1 << j)] = max(dp[mask | (1 << j)], dp[mask] * ithperson_probability_at_jth_area[tot][j]);
                }
            }
        }
    printf("%0.06lf\n",100.0*dp[(1<<n)-1]);

   return 0;
}
