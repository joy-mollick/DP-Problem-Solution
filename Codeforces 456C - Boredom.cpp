
/// Codeforces - 456C - Boredom
/// Category - Dp (maximum contiguous sum likewise technique)

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod=1000000007;

const int mx=100001;

ll tot[mx];

map<int,int>mp;
vector< pair<int,int> > v;

int main()

{
    ll n,num;
    cin>>n;
    while(n--)
    {
        cin>>num;
        mp[num]++;
    }
    map<int,int>::iterator itr;
    for(itr=mp.begin();itr!=mp.end();itr++)
    {
        int cnt=itr->second;
        int number=itr->first;
        v.push_back(make_pair(number,cnt));
    }
    int sz=v.size();
    ll val;
    /// we will now run a loop to compute function ,f(i)
    /// f(i)=max(f(i-1),f(i-2)+cnt(i)*i)
    for(int i=0;i<sz;i++)
    {
        int prev = i - 1;
        /// finding such prev which is obviously at most (i-2)
        if(prev>=0 && v[prev].first+1==v[i].first) prev--;
        /// cnt(i)*i
        val=1ll*v[i].first*v[i].second;
        if(prev==-1) {tot[i]=val;}
        /// else f(i)=f(i-2)+cnt(i)*i.
        else tot[i]=tot[prev]+val;
        ///if this is not first element ,then compare it.
        if(i!=0)
            tot[i]=max(tot[i-1],tot[i]);
    }
    cout<<tot[sz-1]<<endl;

    return 0;
}
