class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int sz=A.size();
        if(sz==1) return 1;
        int increase=1;
        int decrease=1;
        int ans=1;
        for(int i=1;i<sz;i++)
        {
            if(A[i]>A[i-1])
            {
                increase=decrease+1;
                decrease=1;
            }
            else if(A[i]<A[i-1])
            {
                decrease=increase+1;
                increase=1;
            }
            else
            {
                increase=1;
                decrease=1;
            }
            ans=max(ans,max(increase,decrease));
        }
        return ans;
    }
};
