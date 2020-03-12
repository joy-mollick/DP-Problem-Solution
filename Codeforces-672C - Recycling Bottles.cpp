#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

long double dp[100001][2][2];


long double dis(long double x1,long double y1,long double x2,long double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}


int main()

{
    ios_base::sync_with_stdio(false);
    double adilx,adily,berax,beray,binx,biny;
    cin>>adilx>>adily>>berax>>beray>>binx>>biny;
    int q;
    cin>>q;
     double co_ordinatex,co_ordinatey;
    double bin_to_bottle[q];
    double adil_to_bottle[q];
    double bera_to_bottle[q];
    for(int i=0;i<q;i++)
    {
       cin>>co_ordinatex>>co_ordinatey;
       bin_to_bottle[i]=dis(co_ordinatex,co_ordinatey,binx,biny);
       adil_to_bottle[i]=dis(co_ordinatex,co_ordinatey,adilx,adily);
       bera_to_bottle[i]=dis(co_ordinatex,co_ordinatey,berax,beray);
    }
    // base case
    dp[0][0][0]=2*bin_to_bottle[0];// no one take only bin to bottle and again make bottle back to bin total 2*bottle/bin dist
    dp[0][1][0]=adil_to_bottle[0]+bin_to_bottle[0];//Only adil start with this that means adil take this from adil's position and make bottle back to bin ,where bera will not take. only Adil
    dp[0][0][1]=bera_to_bottle[0]+bin_to_bottle[0];//Only bera start with this that means bera take this from bera's position and make bottle back to bin ,where Adil will not take. only Bera
    dp[0][1][1]=1e18;// both adil and bera will not possible to take first one so this case is not possible means infinity
    for(int i=1;i<q;i++)
    {
        // This holds distance from bin to bottle and bottle to bin only assuming none can start to take neither adil nor bera
        dp[i][0][0]=dp[i-1][0][0]+2*bin_to_bottle[i];
        // This holds that only adil take all bottles and back to bin and adil starts with ith one ,keep minimum
        dp[i][1][0]=min(dp[i-1][1][0]+2*bin_to_bottle[i],dp[i-1][0][0]+adil_to_bottle[i]+bin_to_bottle[i]);
        // This holds that only bera take all bottles and back to bin and bera starts with ith one ,keep minimum
        dp[i][0][1]=min(dp[i-1][0][1]+2*bin_to_bottle[i],dp[i-1][0][0]+bera_to_bottle[i]+bin_to_bottle[i]);
        //this states that both adil and bera collect bottles
        dp[i][1][1]=min(dp[i-1][1][1]+2*bin_to_bottle[i],min(dp[i-1][1][0]+bera_to_bottle[i]+bin_to_bottle[i],dp[i-1][0][1]+adil_to_bottle[i]+bin_to_bottle[i]));
    }
    long double ans=min(dp[q-1][1][0],min(dp[q-1][0][1],dp[q-1][1][1]));
    // Take minimum from three cases when only adil takes all bottles dp[q-1][1][0] ,when only bera takes all bottles dp[q-1][0][1] , when both take participation to collect bottle to bin dp[q-1][1][1]
    cout << fixed<<setprecision(6)<<ans;
    return 0;
}
