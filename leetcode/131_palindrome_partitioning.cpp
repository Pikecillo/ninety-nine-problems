class Solution {
public:
    bool is_palindrome(const string &s) {
        int i = 0, j = s.size() - 1;
        
        while(i < j) {
            if(s[i++] != s[j--])
                return false;
        }
        
        return true;
    }

    unordered_map<int, vector<int>> all_palindromes(const string &s) {
        unordered_map<int, vector<int>> palindromes;
        
        for(int i = 0; i < s.size(); i++) {
            palindromes[i] = vector<int>(1, 1);
            
            for(int j = 2; j <= s.size() - i; j++) {
                if(is_palindrome(s.substr(i, j)))
                    palindromes[i].push_back(j);
            }
        }
        
        return palindromes;
    }

    void partition(const string &s, const unordered_map<int, vector<int>> palindromes,
        vector<vector<string>> &partitions, vector<string> current, int index) {
            if(index >= s.size()) {
                partitions.push_back(current);
                return;
            }
            
            for(int i = 0; i < palindromes.at(index).size(); i++) {
                int size = palindromes.at(index)[i];
                current.push_back(s.substr(index, size));
                partition(s, palindromes, partitions, current, index + size);
                current.pop_back();
            }
        }

    vector<vector<string>> partition(string s) {
        unordered_map<int, vector<int>> palindromes = all_palindromes(s);
        vector<vector<string>> partitions;
        
        partition(s, palindromes, partitions, vector<string>(), 0);
        
        return partitions;
    }
};
