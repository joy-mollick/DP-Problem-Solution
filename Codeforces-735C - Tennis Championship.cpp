    #include<bits/stdc++.h>


    using namespace std;

    typedef unsigned long long ll;

    ll dp[20000];

    int main()

    {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        ll n;
        cin>>n;
        dp[0]=1;
        dp[1]=2;
        int i=1;
        while(dp[i]<=n)
        {
            i++;
            dp[i]=dp[i-1]+dp[i-2];
        }
        cout<<(i-1)<<endl;
    }
