

/// print LIS in O(nlogn) time 
/// Fantastic one !


/// greedy and binary search 

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>d;
    vector<int>T;
    int ans,n,x;
     cin>>n;
    int f[n];

     int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>x;
        arr[i]=x;
        /// it will find the value equal to or greater than present value
        vector<int>::iterator it=lower_bound(d.begin(),d.end(),x);
        /// keeping length of lis till i 
        f[i]=it-d.begin()+1;
        if(it==d.end()) d.push_back(x);
        /// it means x is the last value of lis of lebgth d.begin()-it
        else *it=x;
    }

    ans=d.size();
    cout<<ans<<endl;
    int require=ans;

    for(int i=n-1;i>=0;i--)
    {
        if(f[i]==require) {T.push_back(arr[i]);
        require--;}
    }

    /// the size of LIS 
    int sz=T.size();

    /// printing LIS 
    while(sz--)
    {
        cout<<T[sz]<<" ";
    }

    cout<<endl;


    return 0;
}
