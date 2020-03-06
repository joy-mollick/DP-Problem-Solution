
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()

{
    int n,k;
    cin>>n>>k;
    vector<int>dp;
    for(int i=1;i<=n;i++)
    {
        if(k>0) {dp.push_back(2*i); dp.push_back(2*i-1);}
        else {dp.push_back(2*i-1);dp.push_back(2*i);}
        k--;// each pair of two numbers will make effect on k
    }

    for(int i=0;i<dp.size();i++) cout<<dp[i]<<" ";

    cout<<endl;

    return 0;
}
