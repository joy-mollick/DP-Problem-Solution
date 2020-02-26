#include<bits/stdc++.h>
using namespace std;

long int mod=1e9+7;

typedef long long int ll;

int dp[1<<11][1001];
int fact[]={1,1,2,6,24,120,620,4340,34720,312480,3124800};
int cnt[12];
char s[12];

int main()
{
    int i,t,ans,d,n;
    scanf("%d",&t);
    for(int caso=1;caso<=t;caso++)
    {
        scanf("%s %d",s,&d);
        n=strlen(s);
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)    {cnt[s[i]-'0']++;}
        dp[0][0]=1;// base case when no number choosen and divisible by d is one
        // dp[mask][k] states that how much x numbers permutation has remainder k by d ,where x is number of bit on in mask
        for(int mask=0;mask<(1<<n);mask++)
        {
            for(int i=0;i<n;i++)
            {
                if(mask&(1<<i)) continue;// if ith bit is on then no need to take this

                for(int k=0;k<d;k++)
                {
                    int wth_ith_on=mask|(1<<i);
                    dp[wth_ith_on][(k*10+(s[i]-'0'))%d]+=dp[mask][k];
                }
            }
        }
        int ans=dp[(1<<n)-1][0];
        //cout<<ans<<endl;
        for(int i=0;i<n;i++) {ans=ans/fact[cnt[s[i]-'0']];cnt[s[i]-'0']=0;}
                printf("Case %d: %d\n",caso,ans);
    }
    return 0;
}
