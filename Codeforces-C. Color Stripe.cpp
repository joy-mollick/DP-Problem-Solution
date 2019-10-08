
#include<bits/stdc++.h>

using namespace std;

int main()

{
    map<char,int>m;
    map<int,char>m1;
    char c='A';
    int i=1;
    for(;c<='Z';c++,i++)
    {
        m[c]=i;
        m1[i]=c;
    }
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int arr[s.size()];
    for(int i=0;i<s.size();i++)
    {
        arr[i]=m[s[i]];
    }
    if(n==1)
    {
        cout<<"0"<<endl;
        cout<<s<<endl;
        return 0;
    }
    int cnt=0;
    if(k>2){
    for(int j=1;j<s.size()-1;j++)
    {
        if(arr[j]==arr[j-1])
        {
            for(int i=1;i<=k;i++)
            {
                if(arr[j-1]!=i&&arr[j+1]!=i)
                {
                    arr[j]=i;
                    cnt++;
                    break;
                }
            }
            if(arr[j]==arr[j-1])
            {
                if(arr[j]==1)
                {
                    arr[j-1]=2;
                    cnt++;
                }
            }
        }
    }
    int sz=s.size();
    if(arr[sz-1]==arr[sz-2])
    {
        if(arr[sz-2]==1) arr[sz-1]=2;
        else arr[sz-1]=1;
        cnt++;
    }
    cout<<cnt<<endl;
    for(int i=0;i<s.size();i++)
    {
        cout<<m1[arr[i]];
    }
    cout<<endl;}
    else
    {
        string s1="";
        string s2="";
        int t=n;
        int carry=t%2;
        t=t/2;
        while(t--)
        {
            s1+="AB";
            s2+="BA";
        }
        if(carry) {s1+='A';s2+='B';}
        int diff1=0,diff2=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=s1[i]) diff1++;
            if(s[i]!=s2[i]) diff2++;
        }
        if(diff1<=diff2) {cout<<diff1<<endl;cout<<s1<<endl;}
        else {cout<<diff2<<endl;cout<<s2<<endl;}
    }
    return 0;
}
