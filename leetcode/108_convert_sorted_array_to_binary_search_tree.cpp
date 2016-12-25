/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    using Iterator = vector<int>::iterator;

    TreeNode* sortedArrayToBST(const Iterator &begin, const Iterator &end) {
        if(begin == end)
            return nullptr;
            
        Iterator split = begin + distance(begin, end) / 2;
        TreeNode *root = new TreeNode(*split);
        
        root->left = sortedArrayToBST(begin, split);
        root->right = sortedArrayToBST(split + 1, end);
        
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums.begin(), nums.end());
    }
};
