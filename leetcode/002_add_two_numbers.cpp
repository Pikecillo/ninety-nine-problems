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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = nullptr, *head_res = nullptr;
        int carry = 0;
        
        while(l1 || l2 || carry) {
            int sum = carry;
            
            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            if(!res) {
                res = new ListNode(sum % 10);
                head_res = res;
            }
            else {
                head_res->next = new ListNode(sum % 10);
                head_res = head_res->next;
            }
            
            carry = sum / 10;
        }
        
        return res;
    }
};
