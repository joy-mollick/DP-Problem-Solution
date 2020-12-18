
/// Time - 0.014s
/// LightOj - 1031 - Easy Game 
/// Classical dp + recurrence


/// when one will pick then there is two options
/// They are i or j , i holds for left one index and j holds for right one index.
/// if we choose i ,then second one has two options f(i+1,j-1) or f(i+2,j)
/// if we choose j , then second one has two options f(i,j-2) or f(i+1,j-1)
/// the first player has to get if i ,then Vi+ min( f(i+1,j-1) or f(i+2,j) ) else has to get Vj+ min( f(i,j-2) or f(i+,j-1) )
/// we will fill up this table cleverly inshaallah

/// But here ,we can take contiguous coins .its different is that we will keep only difference .


#include<bits/stdc++.h>

#define LL long long
#define maxn 110

using namespace std;

int table[maxn][maxn];
int sum[maxn];


int main()

{
    int T,n,cas=0;

    cin>>T;

    while(T--)
    {
        cas++;
        cin>>n;
        int coin[n+1];
        for(int i=1;i<=n;i++) cin>>coin[i];

        sum[0]=0;

        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+coin[i];

        memset(table,0,sizeof(table));

        /// range is len
               for(int len=1; len<=n; len++) {
            for(int i=1; i+len-1<=n; i++)
            {
                int j=i+len-1;
                table[i][j]=sum[j]-sum[i-1];
                for(int k=i; k<j; k++)
                {
                    /// taking (k-i+1) numbers from start.
                    /// taking (j-k+1) numbers from end  .
                    int taking_start=sum[k]-sum[i-1]-table[k+1][j];
                    int taking_end=sum[j]-sum[k]-table[i][k];
                    
                    table[i][j]=max(table[i][j],max(taking_start,taking_end));
                }
            }
               }

            printf("Case %d: %d\n",cas,table[1][n]);
    }
    return 0;
}
