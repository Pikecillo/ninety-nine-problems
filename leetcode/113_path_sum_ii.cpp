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
    void pathSum(TreeNode* root, int sum, vector<vector<int>>& all_paths,
		 vector<int>& path) {
        if(root == nullptr)
            return;
            
        path.push_back(root->val);
            
        if(root->left == nullptr && root->right == nullptr
	   && sum == root->val) {
            all_paths.push_back(path);
            path.pop_back();
            return;
        }
        
        sum = sum - root->val;
        
        pathSum(root->left, sum, all_paths, path);
        pathSum(root->right, sum, all_paths, path);
        
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> all_paths;
        vector<int> path;
        
        pathSum(root, sum, all_paths, path);
        
        return all_paths;
    }
};
