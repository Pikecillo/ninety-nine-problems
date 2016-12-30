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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> nodes;
        vector<vector<int>> levels;
        
	if(root)
	    nodes.push(root);
        
        while(!nodes.empty()) {
	    levels.push_back(vector<int>());

	    const int level_size = nodes.size();

	    for(int i = 0; i < level_size; i++) {
		TreeNode *node = nodes.front();
		nodes.pop();

		levels.back().push_back(node->val);

		if(node->left)
		    nodes.push(node->left);
		if(node->right)
		    nodes.push(node->right);
            }
        }
        
        return levels;
    }
};
