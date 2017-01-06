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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> traversal;
        stack<TreeNode*> s;
     
        s.push(root);
        
        while(!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            
            if(node) {
                traversal.push_back(node->val);
            
                s.push(node->right);
                s.push(node->left);
            }
        }
        
        return traversal;
    }
};
