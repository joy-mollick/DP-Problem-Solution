
/// Codeforces: C. Geometric Progression
/// Category : data structure + dp.

#include<bits/stdc++.h>

using namespace std;

const int mx=2*100001;

unordered_map<long long,long long>dpleft,dpright;

int main()

{
    long long ans=0ll;
    long long n,k,num,nm;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>num;
        dpright[num]++;
        arr[i]=num;
    }

    for(int j=0;j<n;j++)
    {
         ///erase this element,as it itself explore for only right side count.
        dpright[arr[j]]--;
        if((arr[j]%k==0))
        {
            long long  left=(arr[j]/k);
            long long left_count=dpleft[left];
            long long  right=(arr[j]*k);
            long long right_count=dpright[right];
            ans+=(left_count*right_count);
        }
        /// it will be use for only
        dpleft[arr[j]]++;
    }
    cout<<ans<<endl;

    return 0;
}
