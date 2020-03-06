
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll p[1002];
ll dp[1002];
const ll mod=1e9+7;

int main()

{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];// p[i] states when number of crosses is odd then from i in which numbered room he can go
    }

     // Now, we can only go to N and from there you can go to N+1 only and only when the number of crosses on N'th room ceiling  will be even
    // So, we have to compute the_number_of_moves for any cell i ,to make number of moves even means go to i and from there go to p[i] and....and back to i now number of crosses will be on i even . now he can go i to i+1.
    // dp[i] = 1 + (dp[p[i]]+1) + (dp[p[i]+1]+1) + ... + (dp[i-1]+1) (the first 1 is the initial move from i to p[i]).,here it means that if we can make even number of crosses on i-1 .dp[i-1] ,then one extra move can go you from i-1 to i.

    for(int i=1;i<=n;i++)
    {
        // in every first (odd) move from i he will go p[i] one move is happened
        ll total_moves_back_to_i=1;
        for(int P=p[i];P<=i-1;P++)
        {
            total_moves_back_to_i+=(1ll+dp[P])%mod;
        }
        dp[i]=(total_moves_back_to_i%mod);
    }

    ll total_moves=0;

    for(int i=1;i<=n;i++) total_moves+=dp[i]%mod;
    
    // total_moves states the sum of every steps of ith cell to make that cell's cross even (mean you enter into cell i and back to i again to make it's cross times even this is stated by dp[i]) 
    // so now every cell is prepared for go i+1 th cell from it. That means we have to add the extra moves from 1 to 2(1+1) then from 2 to 3(2+1) ....to n+1 cell means n moves 

    total_moves=(total_moves+n)%mod;

    cout<<total_moves<<'\n';

    return 0;
}
