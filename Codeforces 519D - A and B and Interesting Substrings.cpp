#include<bits/stdc++.h>

using namespace std;

// dp and data structure combined


int main()
{
	long long val[26];
	memset(val,0,sizeof(val));
	for(int i=0;i<26;i++) cin>>val[i];
	string s;
	cin>>s;
	int n=s.size();
	map<long long,int>m;
	vector<int>v[26];
	long long sum=0ll;
	long long dp[n];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<s.size();i++)
    {
        sum=sum+(val[(s[i]-'a')]);
        dp[i]=sum;
        v[s[i]-'a'].push_back(i);
    }
    // we will iterate through all 26 characters which will be the last and first element
    long long ans=0;
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            int pos=v[i][j];
            if(pos!=0){
            long long sum=dp[pos-1];
            //cout<<sum<<" "<<i<<" "<<(pos-1)<<endl;
            ans=ans+m[sum];}
            m[dp[pos]]++;
        }
        m.clear();
    }
    cout<<ans<<endl;
}
