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
    bool isMirrored(TreeNode *root1, TreeNode *root2) {
        if(root1 == nullptr && root2 == nullptr)
            return true;
            
        if(!root1 || !root2)
            return false;
            
        return root1->val == root2->val
	    && isMirrored(root1->left, root2->right)
            && isMirrored(root1->right, root2->left);
    }

    bool isSymmetric(TreeNode *root) {
        if(!root)
            return true;
            
        return isMirrored(root->left, root->right);
    }
};
