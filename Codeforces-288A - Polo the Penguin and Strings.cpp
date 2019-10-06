    #include<bits/stdc++.h>


    using namespace std;

    #define inf 1e17

    typedef unsigned long long ll;

    int main()

    {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        // classical dp problem , only think about two adjacent state (Reversed or Not) there is four possibilities to go next step
        // s[i]>=s[i-1] || s[i]>= R(s[i-1]) || R(s[i])>= s[i-1] || R(s[i])>=R(s[i-1])
       int n,k;
       cin>>n>>k;
       if(n<k)
       {
           cout<<"-1"<<endl;
           return 0;
       }
       else if(k==n)
       {
           char ch='a';
           while(k--)
           {
               cout<<ch;
               ch++;
           }
           cout<<endl;
           return 0;
       }
       else if(k==1&&n!=1)
       {
           cout<<"-1"<<endl;
           return 0;
       }
       else if(k==1&&n==1)
       {
           cout<<"a"<<endl;
           return 0;
       }
       int tms=n-k+2;
       k=k-2;
       int tims=tms>>1;
       int xtra=tms%2;
       //cout<<tims<<endl;
       while(tims--)
       {
           cout<<"ab";
       }
       if(xtra) cout<<"a";
       char c='c';
       for(int i=0;i<k;i++,c++)
       {
           cout<<c;
       }
       cout<<endl;
    }
