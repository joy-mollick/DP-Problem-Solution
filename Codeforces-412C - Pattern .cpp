#include<bits/stdc++.h>

using namespace std;

// greedy and two pointers

typedef long long ll;

// concatenation lexicographically small
char dp[100001];
char arr[100001];

int main()

{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int n;
    scanf("%d",&n);
    scanf("%s",arr);
    int len=strlen(arr);
    for(int i=0;i<len;i++) dp[i]=arr[i];// take all character of first string as base string

    // dp string will be changed dynamically comparing to other string
    // when in i position at least one charcter vary then put ?

    for(int i=1;i<n;i++)
    {
        scanf("%s",arr);
        for(int j=0;j<len;j++){
        if(dp[j]=='*') continue;

        else if(dp[j]!=arr[j])
        {
            if(dp[j]!='?'&& arr[j]!='?') {dp[j]='*';}
            else
            {
                if(dp[j]=='?') dp[j]=arr[j];
            }
        }

        }
    }

    for(int i=0;i<len;i++)
    {
        if(dp[i]=='*') dp[i]='?';
        else if(dp[i]=='?') dp[i]='x';
    }
    printf("%s\n",dp);
}
