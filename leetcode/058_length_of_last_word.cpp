class Solution {
public:
    int lengthOfLastWord(string s) {
        bool seen_letter = false;
        int length = 0;
        
        for(int i = s.size() - 1; i >= 0; i--) {
            if(!seen_letter && s[i] != ' ')
                seen_letter = true;
                
            if(seen_letter) {
                if(s[i] == ' ')
                    break;
                length++;
            }
        }
        
        return length;
    }
};
