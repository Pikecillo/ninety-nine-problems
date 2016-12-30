/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode *findMiddle(ListNode* begin, ListNode* end) {
        int i = 0;        
	ListNode *middle = begin;

        while(begin != end) {
            begin = begin->next;

	    if(i++ % 2) {
		middle = middle->next;
	    }
        }
        
        return middle;
    }

    TreeNode *sortedListToBST(ListNode* begin, ListNode* end) {
        if(begin == end) {
            return nullptr;
        }
        
        ListNode *middle = findMiddle(begin, end);
        TreeNode *root = new TreeNode(middle->val);
        
        root->left = sortedListToBST(begin, middle);
        root->right = sortedListToBST(middle->next, end);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, nullptr);   
    }
};
