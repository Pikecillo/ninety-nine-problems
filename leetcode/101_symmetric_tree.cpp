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
        return (root1 == nullptr && root2 == nullptr)
	    || (root1 && root2 && root1->val == root2->val
		&& isMirrored(root1->left, root2->right)
		&& isMirrored(root1->right, root2->left));
    }

    bool isSymmetric(TreeNode *root) {
        return !root || isMirrored(root->left, root->right);
    }
};
