class Solution {
public:
    bool is_vowel(char c) {
        return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
            c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        
        while(i < j) {
            bool i_vowel = is_vowel(s[i]);
            bool j_vowel = is_vowel(s[j]);
            
            if(i_vowel && j_vowel) {
                swap(s[i++], s[j--]);
            } else {
                if(!i_vowel)
                    i++;
                if(!j_vowel)
                    j--;
            }
        }
        
        return s;
    }
};
