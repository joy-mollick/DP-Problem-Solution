
/// Time-0.162s
/// Optimal Playing Two players pick coins from end game
/// Classical dp + recurrence


/// when one will pick then there is two options
/// They are i or j , i holds for left one index and j holds for right one index.
/// if we choose i ,then second one has two options f(i+1,j-1) or f(i+2,j)
/// if we choose j , then second one has two options f(i,j-2) or f(i+1,j-1)
/// the first player has to get if i ,then Vi+ min( f(i+1,j-1) or f(i+2,j) ) else has to get Vj+ min( f(i,j-2) or f(i+,j-1) )
/// we will fill up this table cleverly inshaallah


#include<bits/stdc++.h>

#define LL long long

using namespace std;


int main()

{
    int T,n;

    cin>>T;

    while(T--)
    {
        cin>>n;
        int coin[n];
        for(int i=0;i<n;i++) cin>>coin[i];

        int table[n][n];
        for(int i=0;i<n;i++) table[i][i]=coin[i];/// one range value

        int i=0,j=1;
        while(i<n && j<n)
        {
            table[i][j]=max(coin[i],coin[j]);
            i++,j++;
        }

        i=0;j=2;
         for (int gap = 2; gap < n; ++gap) {
        for (int i = 0, j = gap; j < n; ++i, ++j) {
            // Here x is value of F(i+2, j),
            // y is F(i+1, j-1) and
            // z is F(i, j-2) in above recursive
            // formula

            int x = table[i + 2][j];
            int y = table[i + 1][j - 1];
            int z = table[i][j - 2];
            /// we are fixing how much will be if we get i to j coins.
            table[i][j]=max(coin[i]+min(x,y),coin[j]+min(y, z));
        }
    }
     cout<<table[0][n-1]<<endl;
    }

    return 0;
}
