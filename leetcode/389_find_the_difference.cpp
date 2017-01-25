class Solution {
public:
    char findTheDifference(string s, string t) {
        int count['z' - 'a' + 1] = {0};
        
        for(int i = 0; i < s.size(); i++)
            count[s[i] - 'a']++;
            
        for(int i = 0; i < t.size(); i++)
            count[t[i] - 'a']--;
            
        for(int i = 0; i < 'z' - 'a' + 1; i++)
            if(count[i])
                return 'a' + i;
    }
};
