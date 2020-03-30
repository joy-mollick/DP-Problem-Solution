#include<bits/stdc++.h>

using namespace std;

int main()

{
    ///ios_base::sync_with_stdio(false);
    ///cin.tie(NULL);
    int tc;
    cin>>tc;
    getchar();
    while(tc--)
    {
        vector<int>v;
        string str;
        getline(cin,str);
        stringstream ss;
        ss<<str;
        int val;
        int sum=0;
        while(ss>>val)
        {
            v.push_back(val);
            sum+=val;
        }
        if(sum%2==1) cout<<"NO"<<endl;
        else
        {
            int target=sum>>1;
            bool dp[target+1];
            for(int i=1;i<=target;i++) {dp[i]=false;}
            dp[0]=true;
            for(int i=0;i<v.size();i++)
            {
                int val=v[i];
                for(int j=target;j>=0;j--)/// we can use one times of coin
                {
                    if(val<=j)
                    {
                        dp[j]=dp[j]|dp[j-val];
                    }
                }
            }
            if(dp[target]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
