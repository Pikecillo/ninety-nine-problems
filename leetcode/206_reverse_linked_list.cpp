/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *a = nullptr, *b = head, *c = nullptr;
        
        while(b != nullptr) {
            c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        
        return a;
    }
};
