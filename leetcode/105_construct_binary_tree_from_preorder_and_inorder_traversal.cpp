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

    TreeNode* buildTree(const Iterator &pre_begin, const Iterator &pre_end,
                        const Iterator &in_begin, const Iterator &in_end) {
        if(pre_begin == pre_end)
            return nullptr;
            
        const int val = *pre_begin;
        TreeNode *root = new TreeNode(val);
            
        const Iterator in_split = find(in_begin, in_end, val);
        const Iterator pre_split = pre_begin + distance(in_begin, in_split);
        
        root->left = buildTree(pre_begin + 1, pre_split + 1,
			       in_begin, in_split);
        root->right = buildTree(pre_split + 1, pre_end,
				in_split + 1, in_end);
        
        return root;   
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder.begin(), preorder.end(),
                         inorder.begin(), inorder.end());
    }
};
