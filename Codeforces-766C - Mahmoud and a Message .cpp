#include<bits/stdc++.h>

using namespace std;

// greedy and prefix

const int mod=1e9+7;


int dp[1002];

int dp2[1002];

int freq[26];

string s;

bool can_be_substring(int i, int j)
   {
         int len  = j - i + 1;
         for( ; i <= j; ++i)
         {
              if (freq[ s[i] - 'a'] < len){
                return false;}
         }
         return true;
   }

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    cin>>s;

    int mx=0;

    for(int i=0;i<26;i++) {cin>>freq[i];}

    dp[0]=1;// with no charcter base case 1
    dp2[0]=0;

    for(int i=1;i<=n;++i)

    {
        dp2[i]=INT_MAX;

        for(int k=0;k<i;++k)

        {
            if(can_be_substring(k,i-1)) // if substr(k..i-1) possible then till total ways will be how many split till k-1 stated as
                                        // dp[k] plus dp[i] .total ways of splitting from k to i dp[i] will be added to total ways
                                        // of splitting from 0 to k-1 dp[k] .Inthis way dp[n] holds for total ways from 0 to n-1.
            {
        //cout<<k<<" "<<(i-1)<<endl;
                dp[i]=dp[i]+dp[k];
                dp[i]=dp[i]%mod;
                mx=max(i-k,mx); // if this k to i-1 length is valid then compare with the mx variable which keeps max length till now
                dp2[i]=min(dp2[i],dp2[k]+1);//in every state we keep minimum  number of split

            }


        }

    }
    cout<<dp[n]<<endl<<mx<<endl<<dp2[n]<<endl;
}
