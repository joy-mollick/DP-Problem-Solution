class Solution {
public:
    int maxProduct(vector<string>& words) {
        int sz=words.size();
        vector<int>mask(sz);
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            string s=words[i];
            for(int j=0;j<s.size();j++)
            {
                mask[i]=mask[i]|(1<<(s[j]-'a'));
            }
            for(int k=0;k<i;k++)
            {
                if(!(mask[k]&mask[i]))//no common charcter 
                {
                    ans=max(ans,(int)(words[i].size()*words[k].size()));
                }
            }
        }
        return ans;
    }
};
