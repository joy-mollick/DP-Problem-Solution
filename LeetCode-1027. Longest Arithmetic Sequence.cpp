class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n=A.size();
        vector<unordered_map<int,int> >dp(n);
        int max_ans=0;
        int diff;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                 diff=A[i]-A[j];
                if(dp[j].find(diff)!=dp[j].end())
                {
        dp[i][diff]=max(dp[i][diff],dp[j][diff]+1);
                }
                else
                {
                    dp[i][diff]=max(2,dp[i][diff]);
                }
                 max_ans=max(dp[i][diff],max_ans);
            }
        }
        return max_ans;
    }
};
