class Solution {
public:
    using Iterator = unordered_map<int, pair<int, int>>::iterator;

    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set;
        unordered_map<int, bool> seen;
        
        for(int n: nums) {
            nums_set.insert(n);
            seen[n] = false;
        }
        
        int largest = 1;
        
        for(int n: nums) {
            if(seen[n])
                continue;
                
            int current = 1;
            int m = n - 1;
            
            while(nums_set.find(m) != nums_set.end()) {
                seen[m--] = true;
                current++;
            }
                
            m = n + 1;
            while(nums_set.find(m) != nums_set.end()) {
                seen[m++] = true;
                current++;
            }
            
            if(current > largest)
                largest = current;
        }
        
        return largest;
    }
};
