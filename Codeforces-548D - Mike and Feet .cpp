#include<bits/stdc++.h>

using namespace std;

// dp and data structure combined 


int main()
{
	int n;
	cin>>n;
	int height[n];
	int left[n];
	int right[n];
	int dp[n+1];// length will be 1 to len of array so n+1 should be the size of the array
	memset(left,-1,sizeof(left));
	fill(right,right+n,n);// you can memset to fill up with only -1 or 0 ,so here u can use fill 
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++) cin>>height[i];
	stack<int>s;
	for(int i=0;i<n;i++)
    {
        while(!s.empty()&&height[s.top()]>=height[i]) s.pop();// it will hold close number's position to height[i] which is less than height[i] ,so deleting these greater numbers than height[i] before i is ok
        if(!s.empty()) left[i]=s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop(); // full clear ,otherwise it will make error for computing right[i]

    for(int i=n-1;i>=0;i--)
    {
         while(!s.empty()&&height[s.top()]>=height[i]) s.pop();
        if(!s.empty()) right[i]=s.top();
        s.push(i);
    }

    // left[i] and right[i] hold the value the close position whose value is less than height[i]
    // Then it is obvious that for the length left[i]+1 to right[i]-1 the value height[i] is the minimum element (strength) of that group because all number between left[i] and right[i] exclusively are greater than height[i]
    // It will be clear that after a little bit thought that len = right[i]-1 -left[i]-1 +1 = right[i]-1 -left[i] , and height[i] is minimum of group of length len then it can be ( you can't make sure because other numbers can be also minimum for such group of length  but it may be also minimum)  also minimum for the length len-1,len-2,...1 which are between left[i] and right[i] , right ? so for len ,keep array dp[len]=height[i]
    // As , by one number height[i] , comparison  you can't make sure that this is the maximum of all minimum (strength) of size group length say x ,so you have to compare all compare max(dp[x],dp[x+1],dp[x+2]......dp[n-1])
    // Because all dp[x],dp[x+1].....dp[n-1] state that these numbers can be minimum of length x,x+1.....n-1 so it can be minimum(strength) of all size group 1 to x, 1 to x+1 , 1 to n-1 . So keep maximum of these numbers
    for(int i=0;i<n;i++)
    {
        int len=right[i]-left[i]-1;
        dp[len]=max(dp[len],height[i]);// more than one number height[i] can be minimum of the group size len , so take maximum of all group size len
    }

    // Now we have to calculate exact value of dp[i]

    for(int i=n-1;i>=1;i--)
    {
        dp[i]=max(dp[i],dp[i+1]);// dp[i] can't be strength of size of group greater than i ,but group of size i+1 can be strength of size of group of size i+1 to 1 so take max from the reverse order till to length 1
    }

    for(int i=1;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }

	return 0;
}
