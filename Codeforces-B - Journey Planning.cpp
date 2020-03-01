#include<bits/stdc++.h>

using namespace std;

// greedy and prefix

typedef long long ll;

int main()

{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n;
    ll x;
    cin>>n;
    map<ll,ll>dp;
    ll mx=0;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        ll diff=x-i;
        if(dp.find(diff)==dp.end())
        {
            dp[diff]=x;
        }
        else
        {
            dp[diff]+=x;
        }
        mx=max(mx,dp[diff]);
    }
    cout<<mx<<endl;
}
