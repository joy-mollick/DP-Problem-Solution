
// Returns the maximum value that
// can be put in a knapsack of capacity W by taking from array of size n 


int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int dp[n + 1][W + 1];
 
    // Build table dp[][] in bottom up manner
    for (i = 0; i <= n; i++) 
    {
        for (w = 0; w <= W; w++) 
        {
            if (i == 0 || w == 0) { dp[i][w] = 0;}
            
            /// check by counting this value 
            else if (wt[i - 1] <= w) 
                {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]); 
                }
                
            else {dp[i][w] = dp[i - 1][w];}
        }
    }
 
    return dp[n][W];
}
 
