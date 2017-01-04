class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones, number = 0;
        
        for(int i = 0; i < 32; i++) {
            ones = 0;
            for(int j = 0; j < nums.size(); j++) {
                ones += ((nums[j] >> i) & 1);
            }
            
            if(ones % 3)
                number |= (1 << i);
        }
        
        return number;
    }
};
