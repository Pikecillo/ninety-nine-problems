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
    int maxPathSumFromRoot(TreeNode* root, int &max_sum) {
        if(!root)
            return 0;

        int max_left_sum = max(maxPathSumFromRoot(root->left, max_sum), 0);
        int max_right_sum = max(maxPathSumFromRoot(root->right, max_sum), 0);

        if(root->val + max_left_sum + max_right_sum > max_sum)
            max_sum = root->val + max_left_sum + max_right_sum;

        return root->val + max(max_left_sum, max_right_sum);
    }

    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        
        int max_sum = root->val;
        
        maxPathSumFromRoot(root, max_sum);
        
        return max_sum;
    }
};
