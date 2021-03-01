
/// codeforces D. How many trees?
/// dp problem
/// counting using dp / inclusion-exclusion / divide and conquer 



/// Binary tree is whose left sons are smaller than right sons 
/// So, we will consider dp[i][j] 
/// dp[i][j] states that by i nodes how many trees can be possible whose height is equal or less than j 
/// then we will check assuming k nodes in the left subtree implies i-k-1 nodes on right subtree ,where 0<=k<i 

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[40][40];

int main()
{
   int n, h;
   cin>>n>>h;

   for(int i = 0; i <= n; i ++)
   {
       /// if the trees with 0 nodes then obviously they have 0 heights 
       /// So, this is base case 
       
       dp[0][i] = 1;
   }

   for (int i = 1; i <= n; i++)
   {
	   for (int j = 1; j <= n; j++)
	   {
		   for (int k = 0; k <i; k++)
		   {
		       /// assuming k nodes on left 
		       /// and i-k-1 nodes on right 
		       /// and one node as root 
		       /// total k + i - k - 1 + 1 = i nodes 
		       /// j-1 is for assuming root node different 
			   dp[i][j] += dp[k][j - 1] * dp[i - k - 1][j - 1];
		   }
	   }
   }

   cout<<(dp[n][n] - dp[n][h - 1])<<endl;
   
   return 0;
}
