class Solution {
public:
    bool makesquare(vector<int>& nums) {
         int n = nums.size(), sum = 0;
        if(n<4) return false;
        int total_state=1<<n;
        int dp[total_state];
        memset(dp,-1,sizeof(dp));
        int k=4;
        dp[0] = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        if (sum % k) return false;
        int tar = sum/k;
        
        for (int state = 0; state < (total_state); state++) {
            if (dp[state] == -1) continue;  // if current state is illegal, simply ignore it
            for (int i = 0; i < n; i++) {
                if (!(state&(1<<i)) && dp[state]+nums[i] <= tar) {  // if nums[i] is unchosen && choose nums[i] would not cross the target
                    int new_state=state|(1<<i);//ith number will be choosen 
                    dp[new_state] = (dp[state]+nums[i]) % tar;
                }
            }
        }
        return dp[total_state-1] == 0;
    }
};
