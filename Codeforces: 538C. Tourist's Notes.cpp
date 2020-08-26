
/// Codeforces: 538C. Tourist's Notes.
/// Category : greedy and dp .

#include<bits/stdc++.h>

using namespace std;


int main()

{
    int n,m,ans;
    cin>>n>>m;
    pair<int,int>arr[m];
    for(int i=0;i<m;i++) cin>>arr[i].first>>arr[i].second;
    int first,last;
    first=arr[0].first+arr[0].second-1;
    last=n-arr[m-1].first+arr[m-1].second;
    ans=max(first,last);
    bool impossible=false;
    for(int i=1;i<m;i++)
    {
        if(abs(arr[i].second-arr[i-1].second)<=arr[i].first-arr[i-1].first)
        {
            ans=max(ans,max(arr[i].second,arr[i-1].second));
            /// increase in the middle
            int distance=abs(arr[i].first-arr[i-1].first)-abs(arr[i-1].second-arr[i].second);
            ///cout<<distance<<endl;
            ans=max(ans,max(arr[i].second,arr[i-1].second)+distance/2);
        }
        else
        {
            impossible=true;
            break;
        }
    }
    if(impossible) cout<<"IMPOSSIBLE"<<endl;
    else
    {
        cout<<ans<<endl;
    }
    return 0;
}
