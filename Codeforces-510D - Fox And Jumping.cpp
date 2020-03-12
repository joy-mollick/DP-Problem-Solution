#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

// It can be solved by bitmask dp,but this is efficient one 
// Find all possible subsequence's gcd but here one thing is good that unique gcd is not large so every time we are traversing around 1500 iterations inner loop of dp in worst case 

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int,ll>dp;
    int n;
    cin>>n;
    int cards[n];
    ll cost[n];
    for(int i=0;i<n;i++) cin>>cards[i];
    for(int i=0;i<n;i++) cin>>cost[i];

    dp[0]=0ll;
    map<int,ll>::iterator it;
    for(int i=0;i<n;i++)
    {
        for(it=dp.begin();it!=dp.end();it++)
        {
            int gcd=__gcd(cards[i],(it->first));
            if(dp.find(gcd)==dp.end()) dp[gcd]=(it->second)+cost[i];
            else dp[gcd]=min(dp[gcd],(it->second)+cost[i]);
        }
    }
    if(dp.find(1)!=dp.end()) cout<<dp[1]<<'\n';
    else cout<<"-1"<<'\n';
}
