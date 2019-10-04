#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, k;

int main(){
  int n;
  string s;
  cin>>n>>s;
  int same=0;
  for(int i=1;i<n;i++)
  {
      if(s[i]==s[i-1]) same++;
  }
  int alter=n-same;
  int possble_lngth=alter+2;
  int ans=min(n,possble_lngth);
  cout<<ans<<endl;
}
