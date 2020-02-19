#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

ll dp[1<<21 +1];//2^n+1

int main()

{
    ll tc,n;
    cin>>tc;
    while(tc--)
    {
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        cin>>n;
        int choose[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>choose[i][j];
            }
        }
      for (int i = 1; i < (1 << n) ; i++) {
				int num = __builtin_popcount(i);
				for (int j = 0; j < n; j++) {
					if (choose[num-1][j] == 0 || (i & (1 << j)) == 0){
						continue;}
						else{
						int state_wth_jth_off=i & ~(1 << j);
					dp[i] += dp[state_wth_jth_off];
					}
				}
			}
        cout<<dp[(1<<(n))-1]<<'\n';// dp[2*n-1] has binary full of 1 ,as every player's choicelist is set on this , now everyone get one assign how many ways ?

    }

    return 0;
}
