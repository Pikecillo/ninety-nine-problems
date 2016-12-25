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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr)
            return vector<vector<int>>();
        
        queue<TreeNode *> nodes;
        queue<int> depths;
        vector<vector<int>> levels;
        
        nodes.push(root);
        depths.push(0);
        
        while(!nodes.empty()) {
            TreeNode *node = nodes.front();
            int depth = depths.front();
            
            nodes.pop();
            depths.pop();
            
            if(depth == levels.size())
                levels.insert(levels.begin(), vector<int>());
            
            levels.begin()->push_back(node->val);
            
            TreeNode *left = node->left;
            TreeNode *right = node->right;
            
            if(left) {
                nodes.push(left);
                depths.push(depth + 1);
            }
            
            if(right) {
                nodes.push(right);
                depths.push(depth + 1);
            }
        }
        
        return levels;
    }
};
