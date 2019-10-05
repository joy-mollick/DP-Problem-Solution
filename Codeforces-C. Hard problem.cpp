    #include<bits/stdc++.h>


    using namespace std;

    #define inf 1e17

    typedef unsigned long long ll;

    int main()

    {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        // classical dp problem , only think about two adjacent state (Reversed or Not) there is four possibilities to go next step
        // s[i]>=s[i-1] || s[i]>= R(s[i-1]) || R(s[i])>= s[i-1] || R(s[i])>=R(s[i-1])
        ll n,ci;
        cin>>n;
        ll dp[n][2];
        ll cst[n];
        for(int i=0;i<n;i++)
        {
            cin>>cst[i];
            dp[i][1]=inf;// dp[i][0] -> no reverse for s[i]
            dp[i][0]=inf;// dp[i][1] ->  reverse for s[i]
        }
        string s[n];
        for(int i=0;i<n;i++)  cin>>s[i];
        dp[0][0]=0;// no reverse
        dp[0][1]=cst[0];// reverse
        for(int i=1;i<n;i++)
        {
            string si=s[i];
            string rsi=si;
            reverse(rsi.begin(),rsi.end());
            string sio=s[i-1];
            string rsio=sio;
            reverse(rsio.begin(),rsio.end());
            bool ok=false;
            if(si>=sio) {dp[i][0]=dp[i-1][0];ok=true;}
            if(si>=rsio) {dp[i][0]=min(dp[i][0],dp[i-1][1]);ok=true;}
            if(rsi>=sio) {dp[i][1]=dp[i-1][0]+cst[i];ok=true;}
            if(rsi>=rsio) {dp[i][1]=min(dp[i][1],dp[i-1][1]+cst[i]);ok=true;}
            if(ok==false) {cout<<"-1"<<endl;return 0;}
        }
        ll ans=min(dp[n-1][0],dp[n-1][1]);
        if(ans==inf) {cout<<"-1"<<endl;return 0;}
        cout<<ans<<endl;
    }
