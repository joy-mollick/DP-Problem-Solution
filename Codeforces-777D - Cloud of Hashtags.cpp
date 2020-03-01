#include<bits/stdc++.h>

using namespace std;

// greedy and prefix

typedef long long ll;

int main()

{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n;
    cin>>n;
   string dp[n];
   for(int i=0;i<n;i++)
   {
       cin>>dp[i];
   }

   for(int i=n-2;i>=0;i--)
   {
       if(dp[i]>dp[i+1]){
       int pointer=0;
       while(pointer<min(dp[i].length(),dp[i+1].length()) && dp[i][pointer]==dp[i+1][pointer]) pointer++;
       dp[i].resize(pointer);
       }
   }

   for(int i=0;i<n;i++) cout<<dp[i]<<'\n';
}
