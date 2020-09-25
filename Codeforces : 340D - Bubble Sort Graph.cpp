
/// Codeforces : 340D - Bubble Sort Graph.
/// Category : dp +greedy.


/// finding long LIS in O(nlogn) 

#include<bits/stdc++.h>


using namespace std;

const int mx=300005;

typedef long long ll;


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,x;
    vector<int>v;

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>x;
        auto it=lower_bound(v.begin(),v.end(),x);
        if(it==v.end()) v.push_back(x);
        else v[it-v.begin()]=x;
    }

    cout<<(int)v.size()<<endl;

	return 0;
}
