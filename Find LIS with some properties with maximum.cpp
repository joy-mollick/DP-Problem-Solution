

/// It is actually to find the correct LIS with some properties 
/// Here, properties is r*r*h .
/// So we will find such LIS whose r*r*h is maximum 

/// dp + data structure 
/// we will use BIT 
/// By BIT , we will find the maximum properties between 1 to pos-1
/// So,dp[i] means what can be maximum properties when arr[i] is the last value of any LIS 

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

// Time Complexity O(nlogn)

const double pii=acos(-1.0);

const int MAXN =  1000002;
ll tree[MAXN], A[MAXN] ;

ll query(int idx)
{
 ll mx = 0ll;
 while (idx > 0){
  mx = max(mx,tree[idx]);
  idx -= (idx & -idx);
 }
 return mx;
}

void update(int idx ,ll val)
{
  /// keeping all time max value
 while (idx <= MAXN)
    {
  tree[idx]= max(val,tree[idx]);
  idx += (idx & -idx);
 }

}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<ll>vol_without_pi;
    vector<ll>vol;
    ll r,h;
    for(int i=0;i<n;i++)
    {
        cin>>r>>h;
        vol_without_pi.push_back(r*r*h);
        vol.push_back(r*r*h);
    }
    sort(vol_without_pi.begin(),vol_without_pi.end());
    vector<ll>::iterator ip=unique(vol_without_pi.begin(), vol_without_pi.end());
    vol_without_pi.resize(distance(vol_without_pi.begin(),ip));

    ll res=0ll;
    ll dp[n+1];
    memset(dp,0,sizeof(dp));

    for(int i=0;i<n;i++)
    {
        int pos=lower_bound(vol_without_pi.begin(),vol_without_pi.end(),vol[i])-vol_without_pi.begin()+1;
        if(pos==1) dp[pos]=vol[i];
        else dp[pos]=query(pos-1)+vol[i];
        update(pos,dp[pos]);
        res=max(dp[pos],res);
    }

      cout<<res<<endl;

    return 0;
}
