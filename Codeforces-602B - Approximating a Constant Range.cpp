    #include<bits/stdc++.h>


    using namespace std;

    typedef long long ll;

    int main()

    {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        int n,a;
        cin>>n;
        int arr[n];
        int mx=0;
        int mn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int j=0;
        int ans=0;
        int diff;
        multiset<int>s;
        for(int i=0;i<n;i++)
        {
            s.insert(arr[i]);
            mx=(*s.rbegin());
            mn=(*s.begin());
            diff=mx-mn;
            while(diff>1)
            {
                s.erase(s.find(arr[j]));
                 mx=(*s.rbegin());
                 mn=(*s.begin());
                 diff=mx-mn;
                 j++;
            }
            ans=max(i-j,ans);
           // cout<<j+1<<" "<<i+1<<endl;
        }
        cout<<ans+1<<endl;

    }
