class Solution {
public:
    vector<string> without_one_letter(string &a)
    {
        vector<string>vec;
        for(int i=0;i<a.size();i++)
        {
            string temp=a;
            string new_temp=temp.erase(i,1);
            vec.push_back(new_temp);
        }
        return vec;
    }
    
    int longestStrChain(vector<string>& words)
    {
        // Divides given word in 17 levels, according to their word length.
        vector<vector<string>> levels(17);
        for (auto &word : words)    levels[word.size()].push_back(word);
        
        unordered_map<string, int> mp;
        for (auto word: words)  mp[word] = 1;
        
        int ans = 1;
        for (int i=2; i<=16; ++i)
        {
            for (int j=0; j<levels[i].size(); ++j)
            {
                vector<string> diffWords = without_one_letter(levels[i][j]);
                
                for (auto word: diffWords)
                {
                    if (mp.find(word) != mp.end())  mp[levels[i][j]] = max(mp[word] + 1, mp[levels[i][j]]);
                }
                
                ans = max (ans, mp[levels[i][j]]);
            }
        }
        
        return ans;
    }
};
