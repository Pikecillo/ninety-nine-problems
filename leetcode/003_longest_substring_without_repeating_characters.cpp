class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> seen(256, -1);
        int i = 0, j = 0, max = 0, current = 0;
        
        while(j < s.size()) {
            if(seen[s[j]] == -1) {
                current++;
                
                if(current > max)
                    max = current;
            } else {
                int k = seen[s[j]];
                current = j - k;
                while(i <= k) {
                    seen[s[i++]] = -1;
                }
            }
            
            seen[s[j]] = j;
            
            j++;
        }
        
        return max;
    }
};
