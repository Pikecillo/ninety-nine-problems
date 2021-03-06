/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while(root) {
	    TreeLinkNode *node = root;
	    
	    while(node) {
		if(node->left) {
		    node->left->next = node->right;
		}		        
		if(node->right && node->next) {
		    node->right->next = node->next->left;
		}		

		node = node->next;
	    }
	    
	    root = root->left;
        }
    }
};
