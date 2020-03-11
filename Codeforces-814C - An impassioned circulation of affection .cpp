
#include<bits/stdc++.h>

using namespace std;

// Classical dp and strings 
// It can be solved with two pointer also but using dp can integrate your skills to other problems 

typedef  long long ll;

const int mx=1501;

int dp[26][mx];


int main()

{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int sz,M;
   char c;
   string s;
   cin>>sz;

   cin>>s;

   for( c='a';c<='z';c++){

        int l=c-'a';

   for(int i=0;i<sz;i++)
   {
       int repaintable=0;

       for(int j=i;j<sz;j++)

       {
           if(s[j]!=c) repaintable++;


           dp[l][repaintable]=max(dp[l][repaintable],j-i+1);
           // dp[i][j] states that by replacing at most j letters ,we can get maximum favourite  Koyomity
       }

   }

   for(int k=1;k<=sz;k++) dp[l][k]=max(dp[l][k],dp[l][k-1]);
   // this is for checking that when axaaaa then what will be the result of 4 a then dp[a][4] obviously zero but answer should be 6 so , we should take maximum for all k greater than number of occurences of different character

   }

   int q;
   int m;
   cin>>q;
   while(q--)
   {
       cin>>m>>c;
       cout<<dp[(c-'a')][m]<<'\n';
   }
   return 0;
}
