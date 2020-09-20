
/// Codeforces : D - Beautiful Array.
/// Category : greedy + classical dp .

#include<bits/stdc++.h>


using namespace std;

const int mx=300001;

typedef long long ll;

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,x;

    cin>>n>>x;
    ll arr[n];

    for(int i=1;i<=n;i++) cin>>arr[i];

    ll dp[n][3];
    memset(dp,0,sizeof(dp));

    ll ans=0ll;

    for(int i=1;i<=n;i++)
    {
        ///only taking max contiguous sum not considering multiplying by x
        dp[i][0]=max(0ll,dp[i-1][0]+arr[i]);
        ///considering adding x*arr[i] to dp[i-1][1] which means we are adding x*arr[i] for a continuous segment
        ///or adding x*arr[i] to dp[i-1][0] means this is the first one we are multiplying x to arr[i]
        dp[i][1]=max(0ll,max(dp[i-1][0],dp[i-1][1])+x*arr[i]);
        ///considering adding only arr[i]
        dp[i][2]=max(0ll,max(dp[i-1][2],dp[i-1][1])+arr[i]);
        ans=max(max(dp[i][0],dp[i][1]),max(ans,dp[i][2]));
    }

    cout<<ans<<endl;

    return 0;
}
