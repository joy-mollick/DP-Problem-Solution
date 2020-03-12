#include<bits/stdc++.h>

using namespace std;

typedef long ll;

string s;
ll dp[5001][5001];
ll palindrome[5001][5001];


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;

    int n=s.length();

    for (int i= 0; i< n; i++){
        palindrome[i][i] = 1ll;
        dp[i][i]=1ll;
    }

        for (int i=0; i<n-1; i++)
    {
        if (s[i] == s[i+1])
        {
            palindrome[i][i+1] = 1ll;
        }
         int j=i+1;
         dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + palindrome[i][j];
    }

    for (int gap=2 ; gap<n; gap++)
    {
        for (int i=0; i<n-gap; i++)
        {
            int j = gap + i;

            if (s[i] == s[j] && palindrome[i+1][j-1] ){
                palindrome[i][j] = 1ll;}

           dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + palindrome[i][j];

        }
    }

    int q,l,r;
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        l--;r--;
        cout<<dp[l][r]<<'\n';
    }

    return 0;
}
