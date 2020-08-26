/// Codeforces: 479C - Exams 
/// Category : Sorting + dp .

#include<bits/stdc++.h>

using namespace std;

///it holds the minimum day number for i exams .
int dp[5001];

int main()

{
    int exams,ai,bi;
    cin>>exams;
    vector<pair<int,int> >v;
    while(exams--)
    {
        cin>>ai>>bi;
        v.push_back(make_pair(ai,bi));
    }
    sort(v.begin(),v.end());
    int sz=v.size();
    for(int i=0;i<sz;i++)
    {
        if(i==0) dp[i]=min(v[i].first,v[i].second);
        else
        {
            if(v[i].second>=dp[i-1]) dp[i]=v[i].second;
            else dp[i]=v[i].first;
        }
    }
    cout<<dp[sz-1]<<endl;

    return 0;
}
