#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod=1e9+7;
const int M = 2e5 + 10;
ll dp[M];

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll r,g;
    cin>>r>>g;
    // there are available r balls and g balls
    ll sum = r + g;
    ll max_h = (sqrt(1ll + 8 * sum) - 1ll) / 2ll;// You can find using the loop but this is more faster than that. this formula has been achieved by using quadratic formula
    dp[0]=1ll;
    //dp[i] states that by using exactly i balls how many different ways we can fill up the levels of tower till max_h inclusively
    for(int h=1;h<=max_h;h++)
    {
        for(int i=r;i>=0;i--)
        {
            if(i-h>=0)
            {
                dp[i]+=dp[i-h];// if h level is filled with h red balls then we have to count how many ways have been filled up by i-h ball already , then we have to add this for i balls in h levels
            }
            dp[i]=(dp[i])%mod;
        }
    }
    ll ans=0ll;
    ll total_bals=(max_h*(max_h+1))>>1ll;
    // now by using all i balls in how many different ways we can fill up levels ,now it is high time to get answer by adding the different ways by checking that other non_filled levels be able to be filled up by green balls or not
    for(int i=0;i<=r;i++)
    {

        if(total_bals-i<=g)// if other levels can be filled up by green then this way will be different ,then add it 
        {
            ans=(ans+dp[i])%mod;
        }
    }
    cout<<ans<<'\n';
}
