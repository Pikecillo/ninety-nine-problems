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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return vector<vector<int>>();
        
        stack<TreeNode*> s;
        vector<vector<int>> levels;
        
        s.push(root);
        
        while(!s.empty()) {
            levels.push_back(vector<int>());
            
            stack<TreeNode*> t;
            
            while(!s.empty()) {
                TreeNode *node = s.top();
                s.pop();
                    
                levels.back().push_back(node->val);
                  
                if(levels.size() % 2 == 0) {  
                    if(node->right)
                        t.push(node->right);
                    if(node->left)
                        t.push(node->left);
                }
                else {
                    if(node->left)
                        t.push(node->left);
                    if(node->right)
                        t.push(node->right);
                }
            }
            
            
            s = t;
        }
        
        return levels;
    }
};
