class Solution {
public:
    void reverse(vector<int>& nums, int i, int j) {
        while(i < j) {
            swap(nums[i++], nums[j--]);
        }
    }

    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        
        if(k) {
	    const int last_index = nums.size() - 1;
            reverse(nums, 0, last_index - k);
            reverse(nums, last_index - k + 1, last_index);
            reverse(nums, 0, last_index);
        }
    }
};
