
#include<bits/stdc++.h>

using namespace std;

#define inf 1e7;


int main() {
    int n,m,k,l,r;
    scanf("%d%d",&n,&m);
    int incrs[n+1][m+1];
    memset(incrs,0,sizeof(incrs));
    for(int j=1;j<=m;j++)
    {
        incrs[1][j]=1;
    }
    int grid[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&grid[i][j]);
        }
    }
    for(int j=1;j<=m;j++)
    {
        for(int i=2;i<=n;i++)
        {
            if(grid[i][j]>=grid[i-1][j])
            {
                incrs[i][j]=incrs[i-1][j]+1;
            }
            else incrs[i][j]=1;
        }
    }
    map< pair<int,int> , bool>M;
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d%d",&l,&r);
        bool ok=false;
        if(M.find(make_pair(l,r))==M.end()){
        for(int j=1;j<=m;j++){
            int tot=(r-l);
            if(incrs[r][j]-incrs[l][j]==tot)
            {
                ok=true;
                break;
            }
        }
        if(ok) printf("Yes\n");
        else printf("No\n");
        M[make_pair(l,r)]=ok;
        }
        else {
                ok=M[make_pair(l,r)];
        if(ok) printf("Yes\n");
        else printf("No\n");
        }
    }
}
