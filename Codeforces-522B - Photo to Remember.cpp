#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int n, m, k;

int main(){
   int n,w,h;
    cin>>n;
   int W[n],H[n];
   int sumw=0;
   multiset<int>s;
   for(int i=0;i<n;i++)
   {
       cin>>w>>h;
       s.insert(h);
       sumw=sumw+w;
       W[i]=w;
       H[i]=h;
   }
   for(int i=0;i<n;i++)
   {
       s.erase(s.find(H[i]));
       int mxh=(*s.rbegin());
       int wd=sumw-W[i];
       cout<<mxh*wd<<" ";
       s.insert(H[i]);
   }
   cout<<endl;
}
