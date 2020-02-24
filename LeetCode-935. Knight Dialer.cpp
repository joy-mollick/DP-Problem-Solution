class Solution {
public:
    long int mod=1e9+7;

    long int knightDialer(int N) {
       long int dp[N+1][10];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<10;i++)
        {
            dp[1][i]=1;// base case
        }
      //{{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};
        map<int,vector<int> >m;
        m[0].push_back(4);m[0].push_back(6);
        m[1].push_back(6);m[1].push_back(8);
        m[2].push_back(7);m[2].push_back(9);
        m[3].push_back(4);m[3].push_back(8);
        m[4].push_back(3);m[4].push_back(9);m[4].push_back(0);
        m[6].push_back(1);m[6].push_back(7);m[6].push_back(0);
        m[7].push_back(2);m[7].push_back(6);
        m[8].push_back(1);m[8].push_back(3);
        m[9].push_back(2);m[9].push_back(4);
        for(int j=2;j<=N;j++)
        {
            for(int i=0;i<10;i++)
            {

            for(int h=0;h<m[i].size();h++)
            {
            dp[j][i]+=(dp[j-1][m[i][h]])%mod;
            }

            }
        }
        long int ans=0;
        for(int dial=0;dial<10;dial++) {ans=(ans+dp[N][dial])%mod;}
        return (ans%mod);
    }

};

