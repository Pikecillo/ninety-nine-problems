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
    using Iterator = vector<int>::iterator;

    TreeNode* buildTree(const Iterator &in_begin, const Iterator &in_end,
                        const Iterator &post_begin, const Iterator &post_end) {
        if(in_begin == in_end)
            return nullptr;
            
        const int val = *(post_end - 1);
        TreeNode *root = new TreeNode(val);
        
        const Iterator in_split = find(in_begin, in_end, val);
        const Iterator post_split = post_begin + distance(in_begin, in_split);
        
        root->left = buildTree(in_begin, in_split,
			       post_begin, post_split);
        root->right = buildTree(in_split + 1, in_end,
				post_split, post_end - 1);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder.begin(), inorder.end(),
                         postorder.begin(), postorder.end());
    }
};
