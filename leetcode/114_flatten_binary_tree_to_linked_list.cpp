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
    void append(TreeNode*& root1, TreeNode*& root2) {
        if(root1 == nullptr) {
            root1 = root2;
            root2 = nullptr;
            return;
        }
        
        if(root2 == nullptr) {
            return;
        }
            
        TreeNode* rightmost = root1;
        while(rightmost->right) {
            rightmost = rightmost->right;
        }
        
        rightmost->right = root2;
    }

    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;
            
        flatten(root->left);
        flatten(root->right);
        
        append(root->left, root->right);
        
        root->right = root->left;
        root->left = nullptr;
    }
};
