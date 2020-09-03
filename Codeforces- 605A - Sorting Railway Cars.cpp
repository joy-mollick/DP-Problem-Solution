
/// Codeforces- 605A - Sorting Railway Cars 
/// Category: greedy + dp.


#include<bits/stdc++.h>

using namespace std;


typedef unsigned long long ll;


int main()

{
    int n,num;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    unordered_map<int, int> mp;
    int dp[n];
    memset(dp, 0, sizeof(dp));
    int maximum = INT_MIN;

    /// finding maximum longest consecutive increasing subsequence 
    for (int i = 0; i < n; i++) {
        if (mp.find(a[i] - 1) != mp.end()) {
            int lastIndex = mp[a[i] - 1] - 1;
            dp[i] = 1 + dp[lastIndex];
        }
        else
            dp[i] = 1;

        mp[a[i]] = i + 1;
        maximum = max(maximum, dp[i]);
    }

    cout<<(n-maximum)<<endl;

    return 0;
}
