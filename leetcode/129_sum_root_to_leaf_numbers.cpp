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
    void sumNumbers(TreeNode* root, int curr, int &total) {
        if(!root) {
            return;
        }
        
        curr = 10 * curr + root->val;
        
        if(!root->left && !root->right) {
            total += curr;
            return;
        }
        
        sumNumbers(root->left, curr, total);
        sumNumbers(root->right, curr, total);
    }

    int sumNumbers(TreeNode* root) {
        int total = 0;
        
        sumNumbers(root, 0, total);
        
        return total;
    }
};
