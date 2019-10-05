    #include<bits/stdc++.h>


    using namespace std;

    typedef long long ll;

    int main()

    {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int v1,v2;
        int tms,diff;
        cin>>v1>>v2;
        cin>>tms>>diff;
        int dp[tms];
        int mxpossfrmrght=(tms-1)*diff+v2;
        int mxpossfrmlft=v1;

        for(int i=0;i<tms;i++)
        {
            dp[i]=min(mxpossfrmrght,mxpossfrmlft);
            mxpossfrmlft+=diff;
            mxpossfrmrght-=diff;
        }
        int ans=0;
        for(int i=0;i<tms;i++)
        {
            ans+=dp[i];
        }
        cout<<ans<<endl;
    }
