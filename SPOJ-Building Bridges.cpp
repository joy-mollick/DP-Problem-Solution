#include<bits/stdc++.h>

using namespace std;

/// Variation of LIS of pair

bool cmp(pair<int,int>a,pair<int,int>b)
{
   if (a.first == b.first)
        return a.second < b.second;

    return a.first < b.first;
}

int main()

{
    int tc;
    scanf("%d",&tc);
    while(tc--){
    int n;
    vector< pair<int,int> >v;
    vector< pair<int,int> >::iterator it;
    scanf("%d",&n);
    int X[n];
    int Y[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&X[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&Y[i]);
    }
    for(int i=0;i<n;i++)
    {
        v.push_back(make_pair(X[i],Y[i]));
    }
    sort(v.begin(),v.end(),cmp);
    int dp[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(v[j].second<=v[i].second)
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int ans=*max_element(dp,dp+n);
    printf("%d\n",ans);
    }
    return 0;
}
