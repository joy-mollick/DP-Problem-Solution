#include<bits/stdc++.h>

using namespace std;

// greedy and two pointers

typedef long long ll;



string s;
ll cumulutivesum[2002];
ll dp[2002];
int palindrome[2002][2002];


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;

    int n=s.length();

    for (int i= 0; i< n; i++)
        palindrome[i][i] = 1;

        for (int i=0; i<n-1; i++)
    {
        if (s[i] == s[i+1])
        {
            palindrome[i][i+1] = 1;
        }
    }

    for (int gap=2 ; gap<n; gap++)
    {
        for (int i=0; i<n-gap; i++)
        {
            int j = gap + i;

            if (s[i] == s[j] && palindrome[i+1][j-1] )
                palindrome[i][j] = 1;

        }
    }

    for(int i=0;i<n;i++)
    {
        ll tot=0;
        for(int j=0;j<=i;j++)
        {
            tot+=palindrome[j][i];
        }
         cumulutivesum[i]=tot;
        if(i!=0) cumulutivesum[i]+=cumulutivesum[i-1];
    }

    // it will store how many strings with ending i are palindrome

    // dp[i] hold how many such pairs are available till i index

    for(int i=0;i<n;i++)
    {
        ll ans=0ll;
        ll tot=0;
        for(int j=0;j<=i;j++)
        {
            ll total_pal_till_j_minus_1=0ll;
            if(j!=0) total_pal_till_j_minus_1=cumulutivesum[j-1];
            tot=total_pal_till_j_minus_1*palindrome[j][i];
            ans=ans+tot;
        }
        dp[i]=ans;
        if(i!=0) dp[i]=dp[i]+dp[i-1];
    }
    cout<<dp[n-1]<<endl;
}
