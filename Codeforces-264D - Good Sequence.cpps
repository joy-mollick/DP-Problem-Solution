
#include<bits/stdc++.h>

using namespace std;

// Simple dp and Number theory and sieve 

typedef long long ll;

#define mx 100003

vector<int>v[mx];
int dp[mx];
bool prime[mx];
void sieve ()
{
    memset(prime, true, sizeof(prime));

    for (int p=2; p<=mx; p++)
    {
        dp[p]=1;
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            v[p].push_back(p);
            for (int i=2*p; i<=mx; i += p) {
                prime[i] = false;
                v[i].push_back(p);// take all number's prime_factors
            }
        }
    }
}

int main()

{
    sieve();
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    int ans=1;

    for(int j=0;j<n;j++)

    {
        int len=1;
        int num=arr[j];
        for(int i=0;i<v[num].size();i++)
        {
            int prime_factor=v[num][i];
            len=max(len,dp[prime_factor]);// dp[prime_factor] states how much longest sequence of numbers ending with arr[j] i.e. num  which has a prime_factor is v[num][i] i.e. prime_factor
        }
        ans=max(ans,len);
        for(int i=0;i<v[num].size();i++)
        {
            int prime_factor=v[num][i];
            dp[prime_factor]=max(dp[prime_factor],len+1);
        }
    }

    cout<<ans<<endl;

}
