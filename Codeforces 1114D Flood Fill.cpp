
/// codeforces Codeforces 1114D Flood Fill
/// Category : Classical DP
/// Fantastic One

/// It is nothing but a longest palindromic finding problem
/// It is greedy to choose a longest palindromic sequence (len) and
/// make (len+1)/2 moves to all equipment same color of that sequence.
/// it is easy to reverse our string and finding lcs of two strings
/// which exactly finds longest palindromic sequence .



#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> a,b;
int dp[5001][5001];

/// finding lcs using dp
void done(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
}

int main()
{
    a.push_back(5001);

    int n,c;

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>c;
        /// ignoring consecutive duplicates 
        if(c!=a.back()) a.push_back(c);
    }

    int sz=a.size()-1;
    b=a;

    reverse(b.begin()+1,b.end());

    done(sz);

    cout<<(sz-(dp[sz][sz]+1)/2)<<endl;

    return 0;
}
