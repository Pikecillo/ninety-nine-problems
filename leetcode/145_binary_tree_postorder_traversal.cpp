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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> traversal;
        stack<TreeNode *> s;
        stack<bool> d;
        
        s.push(root);
        d.push(false);
        
        while(!s.empty()) {
            TreeNode *node = s.top();
            bool done = d.top();
            
            if(node) {
                if(done) {
                    traversal.push_back(node->val);
                    s.pop();
                    d.pop();
                }
                else {
                    s.push(node->right);
                    s.push(node->left);
                
                    d.pop();
                    d.push(true);
                    d.push(false);
                    d.push(false);
                }
            }
            else {
                s.pop();
                d.pop();
            }
        }
        
        return traversal;
    }
};
