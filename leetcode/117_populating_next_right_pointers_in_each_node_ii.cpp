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
            TreeLinkNode *curr = root, *prev = nullptr;
            
            while(curr) {
                if(curr->left || curr->right) {
                    prev = curr;
                    curr = curr->next;
                }
                
                while(curr && !curr->left && !curr->right) {
                    curr = curr->next;
                }
                
                if(prev && prev->left && prev->right) {
                    prev->left->next = prev->right;
                }
                
                TreeLinkNode *from = prev ?
		    (prev->right ? prev->right : prev->left) : nullptr;
                TreeLinkNode *to = curr ?
		    (curr->left ? curr->left : curr->right) : nullptr;
                
                if(from && to) {
                    from->next = to;
                }
            }
            
            if(root->left)
                root = root->left;
            else if(root->right)
                root = root->right;
            else
                root = root->next;
        }
    }
};
