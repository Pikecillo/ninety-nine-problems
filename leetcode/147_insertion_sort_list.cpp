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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr)
            return head;
        
        ListNode *hi = head;
        while(hi->next != nullptr) {
            ListNode *lo = head;
            ListNode *hi_next = hi->next;
            
            if(lo->val > hi->next->val) {
                hi->next = hi_next->next;
                hi_next->next = lo;
                head = hi_next;
            }
            else {
                while(lo->next != nullptr && lo->next->val < hi->next->val && lo != hi) {
                    lo = lo->next;
                }
            
                if(lo != hi && lo->next != nullptr) {
                    // Remove hi->next
                    hi->next = hi_next->next;
            
                    // Insert hi->next after lo
                    ListNode *lo_next = lo->next;
            
                    hi_next->next = lo_next;
                    lo->next = hi_next;
                }
                else {
                    hi = hi->next;
                }
            }
        }
        
        return head;
    }
};
