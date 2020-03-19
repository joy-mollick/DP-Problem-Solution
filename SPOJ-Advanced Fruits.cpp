#include<bits/stdc++.h>

using namespace std;

/// Variation of LCS and SCC 


int main()

{
    string s,s1;
    while(cin>>s>>s1){
        int n=s.size();
        int m=s1.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                }
                else if(s[i-1]==s1[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        /// finding the lcs string
        int index = dp[n][m];

   char lcs[index+1];
   lcs[index] = '\0';
   int i = n, j = m;
   while (i > 0 && j > 0)

   {

      if (s[i-1] == s1[j-1])
      {
          lcs[index-1] = s[i-1];
          i--; j--; index--;
      }

      else if (dp[i-1][j] > dp[i][j-1]){
         i--;}
      else{
         j--;}
   }
        int l1 = 0, l2 = 0;

        /// then printing SCS of s1 and s2 with the help of LCS of s1 and s2
        for(int i=0; i<strlen(lcs); ++i) {

            while(l1 < n && s[l1] != lcs[i]) {
                cout << s[l1];
                ++l1;
            }

            while(l2 < m && s1[l2] != lcs[i]) {
                cout << s1[l2];
                ++l2;
            }

            cout<<lcs[i];
            ++l2, ++l1;
        }

        while(l1<n)
            cout<<s[l1++];
        while(l2<m)
            cout<<s1[l2++];

        cout<<endl;

}
    return 0;
}
