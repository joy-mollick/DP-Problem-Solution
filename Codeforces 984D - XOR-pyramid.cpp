
/// Codeforces 984D - XOR-pyramid
/// Classical dp + Interval dp



/// here if we investigate then we can see that
/// if we want to find xor[1,5]
/// Then we have to do , xor[1,5] = xor[1,4]^xor[2,5] , xor[i,j]=xor[i,j-1]^xor[i+1,j] 
/// In this way , we can proceed our dp procedure

#include<bits/stdc++.h>

using namespace std;

const int mx=5101;

int a[5100];
int xor_[mx][mx];
int dp_max[mx][mx];


int main()

{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int len=0;len<=n;len++)
    {
        for(int i=0;i+len<n;i++)
       {
            if(len==0)
            {
                xor_[i][i]=a[i];
                dp_max[i][i]=a[i];
            }

            else
            {
                xor_[i][i+len]= xor_[i][i+len-1]^xor_[i+1][i+len];
                dp_max[i][i+len] = max(max(dp_max[i][i+len-1],dp_max[i+1][i+len]),xor_[i][i+len]);
            }
        }
    }

    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<dp_max[l-1][r-1]<<'\n';
    }

    return 0;
}
