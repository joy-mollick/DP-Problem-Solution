
/// Codeforces: 608C - Chain Reaction.
/// Category: Classical dp (medium).



#include<bits/stdc++.h>

using namespace std;


const int mxn=1000001;

///dp[i] states that if ith is activated maximum number of destroyed places from 0 to i.
///So,we will check every dp[i] value,assuming ith place is active ,and other suffix places have been destroyed by an extra beacon to the rightest of all beacons.

int dp[mxn];
int b[mxn];

int main()

{
    int n,a,bb,N;
    cin>>n;
    N=n;
    while(n--)
   {
     cin>>a>>bb;
     /// so,b of every position a has been taken
     b[a]=bb;
   }

   /// base case
   if(b[0]>0){
   dp[0]=1;
   }

   int mx=0;

   for(int i=1;i<mxn;i++)
   {
       if(b[i]==0)
       {
           ///there is nothing here in ith position ,so take previous one
           dp[i]=dp[i-1];
       }

       else if(b[i]>=i)
       {
           ///it means that it will vanish all position's activation,so only i is remaining
           dp[i]=1;
       }

       else

       {
           dp[i]=dp[i-b[i]-1]+1;
       }

       mx=max(dp[i],mx);
   }

    cout<<(N-mx)<<endl;

    return 0;
}
