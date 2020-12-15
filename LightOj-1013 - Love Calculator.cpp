
///   Time- 0.002s
///   1013 - Love Calculator
///  LCS + Classical DP

#include<bits/stdc++.h>

using namespace std;


const int MAX =31;

int lcs[MAX][MAX];
long long ans[MAX][MAX];

int main()

{
    int T,n;
    cin>>T;
    int caso=0;
    string s1,s2;
    while(T--)

    {

        caso++;
        cin>>s1>>s2;

        memset(lcs,0,sizeof(lcs));
        memset(ans,0,sizeof(ans));

        int len1=s1.size();
        int len2=s2.size();

        for(int i=0;i<=len1;i++) ans[i][0] = 1;
        for(int j=0;j<=len2;j++) ans[0][j] = 1;

        for(int i=0;i<len1;i++)
        {
            for(int j=0;j<len2;j++)
            {

                if(s1[i]==s2[j])
                {
                    lcs[i+1][j+1]=lcs[i][j]+1;
                    /// when character matches you have to input it
                    ans[i+1][j+1]=ans[i][j];
                }

                else

                {
                    if(lcs[i+1][j]>lcs[i][j+1])
                    {
                        lcs[i+1][j+1]=lcs[i+1][j];
                        /// we are finding the number of lcs strings ,so we have to go lcs's side
                        ans[i+1][j+1]=ans[i+1][j];

                    }
                    else if(lcs[i+1][j]<lcs[i][j+1])
                    {
                         lcs[i+1][j+1]=lcs[i][j+1];
                        /// we are finding the number of lcs strings ,so we have to go lcs's side
                        ans[i+1][j+1]=ans[i][j+1];
                    }
                    /// equal ...
                    else
                    {
                        lcs[i+1][j+1]=lcs[i][j+1];/// you can take also lcs[i+1][j]
                        ans[i+1][j+1]=ans[i][j+1]+ans[i+1][j];
                    }
                }
            }
        }

    printf("Case %d: %d %lld\n", caso,len1 + len2 - lcs[len1][len2],ans[len1][len2]);

    }

    return 0;
}
