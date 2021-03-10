

/// Codeforces 10D - LCIS
/// Category : Classical DP
/// LCS + LIS


/// printing longest common increasing subsequence 

#include<bits/stdc++.h>

using namespace std;


int main()

{
    int n,m;
    cin>>n;
    int arr1[n];
    for(int i=0;i<n;i++) cin>>arr1[i];
    cin>>m;
    int arr2[m],dp[m],parent[m];
    for(int j=0;j<m;j++) cin>>arr2[j];

    for(int k=0;k<m;k++) dp[k]=0;

    for(int i=0;i<n;i++)
    {
        int curr=0,last_one=-1;

        for(int j=0;j<m;j++)
        {
            if(arr1[i]==arr2[j])
            {
                if(curr+1>dp[j])
                {
                    dp[j]=curr+1;
                    parent[j]=last_one;
                }

            }

            if(arr1[i]>arr2[j])
            {
                if(dp[j]>curr)
                {
                    curr=dp[j];
                    last_one=j;
                }
            }
        }
    }

    int ans=0,indx;

    for(int i=0;i<m;i++)
    {
        if(dp[i]>ans)
        {
            ans=dp[i];
            indx=i;
        }
    }

    vector<int>res;

    if(ans>0){

    while(indx!=-1)
    {
        res.push_back(arr2[indx]);
        indx=parent[indx];
    }

    }

    cout<<ans<<endl;
    for(int i=ans-1;i>=0;i--)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;
}
