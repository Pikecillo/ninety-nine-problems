class Solution {
public:
    char findTheDifference(string s, string t) {
        char diff = (char)0;
        
        for(int i = 0; i < s.size(); i++)
            diff ^= s[i];
            
        for(int i = 0; i < t.size(); i++)
            diff ^= t[i];
            
        return diff;
    }
};
