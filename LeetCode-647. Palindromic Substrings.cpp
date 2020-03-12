class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        int palindrome[n][n];
        memset(palindrome,0,sizeof(palindrome));

    for (int i= 0; i< n; i++){
        palindrome[i][i] = 1;
        dp[i][i]=1;
    }

        for (int i=0; i<n-1; i++)
    {
        if (s[i] == s[i+1])
        {
            palindrome[i][i+1] = 1;
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
        return (dp[0][n-1]);

    }
};
