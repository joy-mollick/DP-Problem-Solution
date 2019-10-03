#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, k;

int main(){
  cin>>k;
  string s;
  cin>>s;
  int sz=s.size();
  int pre[sz];
  int sum=0;
  ll cnt=0ll;
  map<int,ll>m;
  for(int i=0;i<sz;i++)
  {
      if(s[i]=='1') sum+=1;
      if(sum==k) cnt=cnt+1ll;
      cnt+=m[sum-k];
      m[sum]++;
  }
  cout<<cnt<<endl;
}
