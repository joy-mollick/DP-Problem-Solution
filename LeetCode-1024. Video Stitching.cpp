class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T)     {
        // Time Complexity O(n*T)
        //First take the maximum one which area from 0             can be covered 
        //Then take the second maximum area can be covered which started from the last maximum area or less than that covered by first clip by second clips and so on till N clips 
        //Then find the one in how much minimum clips can cover the area equal or greater than T 
        int n=clips.size();
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(clips[j][0]<=dp[i-1])
                {
                    dp[i]=max(dp[i],clips[j][1]);
// dp[i] states for how maximum area can be covered by i clips 
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(dp[i]>=T) return i;
        }
        return -1;
        
    }
};
