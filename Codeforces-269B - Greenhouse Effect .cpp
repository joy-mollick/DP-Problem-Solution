
#include<bits/stdc++.h>

using namespace std;

// Simple dp 

const int mx=5002;

int dp[mx];

int main()

{
   int n,m,M;
   double x;
   cin>>n>>m;
   vector<pair<int,double> >v;

   for(int i=0;i<n;i++)
   {
       cin>>M>>x;
       v.push_back(make_pair(M,x));
   }
   dp[0]=1;
   for(int i=1;i<n;i++)
   {
       dp[i]=1;
       for(int j=0;j<i;j++)
       {
           if(v[i].first>=v[j].first)
           {
               if(dp[j]+1>dp[i])
               {
                   dp[i]=dp[j]+1;
                   //cout<<i<<" "<<dp[i]<<endl;
               }
           }
       }
   }

   int mx=*max_element(dp,dp+n);
   int ans=n-mx;
   cout<<ans<<endl;

}
