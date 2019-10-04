    #include<bits/stdc++.h>


    using namespace std;

    typedef long long ll;

    ll dp[20000];

    int main()

    {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        ll n,a;
        cin>>n;
        ll pref[n+1];
        pref[0]=0;
        ll dp[n+1];
        memset(dp,0,sizeof(dp));
        ll sum=0;

        for(int i=1;i<=n;i++)
        {
            cin>>a;
            sum=sum+a;
            pref[i]=sum;// prefix summation of numbers
        }

        if(sum%3!=0) cout<<"0"<<endl;// It's not possible to split this three equal parts

        else
        {
            ll frstprt =sum/3ll;// the frst segment hold the value the one third of sum

            ll secndprt=frstprt*2;//the segment holding the sum of double of frst segment

            // It is guarantee that every segment of three segments should hold sum of segment equal to one third of sum (frstprt)

            ll res=0;

            for(int i=1;i<=n-1;i++)
            {

                 if(pref[i]==secndprt) {res+=dp[i-1];} // if sum equals to sum of the frstprt and secnd prt obviously it will increase by one by aid of previously how many times segment equal to same as one third

                  if(pref[i]==frstprt) {dp[i]=dp[i-1]+1;}// how many times sum holds same as the one third of sum

                 else {dp[i]=dp[i-1];}
            }
            cout<<res<<endl;
        }
    }
