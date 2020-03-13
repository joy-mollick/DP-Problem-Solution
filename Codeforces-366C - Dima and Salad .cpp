#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

// this is a classical dp problem

const int mx=1e5;

int dp[mx+1];
int dpneg[mx+1];

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int k;
    cin>>n>>k;
    int tas[n];
    int cal[n];
    int diff[n];
    for(int i=0;i<n;i++) cin>>tas[i];
    for(int i=0;i<n;i++) cin>>cal[i];
    for(int i=0;i<n;i++) diff[i]=tas[i]-k*(cal[i]);
    for(int i=0;i<=mx;i++) {dp[i]=-mx;dpneg[i]=-mx;}
    //base case
    dp[0]=0;
    dpneg[0]=0;
    ///dp[i] states that how much maximum taste dp[i] can take whose diffsummation is i
    /// now we have to find out max dp whose i will be 0 .But for this some diff should be stored which can't be stored so make positive and store in another dpneg[i]
    for(int i=0;i<n;i++)
    {
        int dif=diff[i];
        if(dif>=0)
        {
            for(int j=mx;j>=dif;j--) // we can choose tas[i] and cal[i] one time only so make precompution from reverse
            {
                dp[j]=max(dp[j],dp[j-dif]+tas[i]);
            }
        }
        else
        {
            dif=dif*(-1);
             for(int j=mx;j>=dif;j--) // we can choose tas[i] and cal[i] one time only so make precompution from reverse
            {
                dpneg[j]=max(dpneg[j],dpneg[j-dif]+tas[i]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<=mx;i++)
    {
        ans=max(ans,dp[i]+dpneg[i]);
        // dp[i] is maximum whose diff is i 
        // dpneg[i] is maximum whose diff is -i 
        // we have to take this summation and check which is maximum as i -i=0 is it's total diff 
    }
    if(ans==0) cout<<"-1"<<endl;
    else cout<<ans<<endl;
}
