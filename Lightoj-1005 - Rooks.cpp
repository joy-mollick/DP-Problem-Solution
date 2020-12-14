
/// Time-0.005s
/// 1005 - Rooks 
///  DP -LOJ , Combinatorics

#include<bits/stdc++.h>

using namespace std;

/// Problem , placing K rooks in N x N board 

const int MAX =31;

long long triangle[MAX + 1][MAX + 1];

void makeTriangle()
{
    int i, j;
    // initialize the first row
    triangle[0][0] = 1; // C(0, 0) = 1

    for(i = 1; i < MAX; i++) {
        triangle[i][0] = 1; // C(i, 0) = 1
        for(j = 1; j <= i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
}

long long fact(long long n)
{
    long long ans=1ll;

    for(long long i=2ll;i<=n;i++)
    {
        ans=(ans*i);
    }

    return ans;
}

int main()

{
    long long T,N,K;
    cin>>T;
    int caso=0;
    makeTriangle();

    while(T--)
    {
        cin>>N>>K;
        caso++;
        if(K>N)
        {
            cout<<"Case "<<caso<<": "<<"0"<<endl;
        }
        else
        {
            long long res=fact(K);
            res=res*triangle[N][K]*triangle[N][K];
            cout<<"Case "<<caso<<": "<<res<<endl;
        }
    }

    return 0;
}
