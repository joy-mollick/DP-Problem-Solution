
/// Codeforces 459E - Pashmak and Graph
/// dp problem
/// Nice problem!!


#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int maxx=300001;

typedef pair<int,int> pi;

vector<pi>edge[maxx];

int temp_dp[maxx];
int dp[maxx];

int main()
{

   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

    int n,m,wei,u,v,U,V;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>wei;
        edge[wei].push_back(make_pair(u,v));
    }

    for(int i=0;i<maxx;i++)
    {
        for(int j=0;j<edge[i].size();j++)
        {
             U=edge[i][j].first;
             V=edge[i][j].second;
            temp_dp[V]=max(temp_dp[V],dp[U]+1);
            /// printf("temp_dp[%d]=%d ,dp[%d]+1 = %d\n",V,temp_dp[V],U,dp[U]+1);
        }

        /// store new dp value for vertices
       for(int j=0;j<edge[i].size();j++)
       {
            int V=edge[i][j].second;
           dp[V]=max(dp[V],temp_dp[V]);
           /// printf("dp[%d]=%d\n",*it,dp[*it]);
       }
    }

    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,dp[i]);

    cout<<ans<<endl;

    return 0;
}
