class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_map<int,int>m;
        int n=A.size();
        int dp[n][n];
        for(int j=0;j<n;j++)
        {
            m[A[j]]=j;
            for(int i=0;i<j;i++)
            {
               dp[i][j]=2;
            }
        }
 //make all two elements pair as 2 in dp[i][j]
        int mx=0;
        for(int j=0;j<n;j++)
        {
            int y=A[j];
            for(int i=0;i<j;i++)
            {
                int x=A[i];
                int diff=y-x;
                int pos_wth_diff=0;
                if(m.find(diff)==m.end()){ continue;}
    // it is not available ignore this
                 pos_wth_diff=m[diff];
                if(pos_wth_diff<i){
    dp[i][j]=max(dp[i][j],dp[pos_wth_diff][i]+1);
                mx=max(mx,dp[i][j]);}
            }
        }
        return mx;
    }
};
