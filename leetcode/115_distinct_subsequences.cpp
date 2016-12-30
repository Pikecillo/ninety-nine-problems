class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> table(t.size() + 1, vector<int>(s.size() + 1, 0));
        
        for(int j = 0; j < table.front().size(); j++) {
            table[0][j] = 1;
        }
        
        for(int i = 1; i < table.size(); i++) {
            for(int j = i; j < table.front().size(); j++) {
                if(t[i - 1] == s[j - 1])
                    table[i][j] = table[i - 1][j - 1] + table[i][j - 1];
                else
                    table[i][j] = table[i][j - 1];
            }
        }
        
        return table.back().back();
    }
};
