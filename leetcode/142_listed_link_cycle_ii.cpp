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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        
        while(fast && slow) {
            fast = fast->next;
            
            if(fast == slow)
                break;
                
            slow = slow->next;
            
            if(fast)
                fast = fast->next;
        }
        
        if(!fast) {
            return nullptr;
        }
        
        while(true) {
            slow = fast;
            
            do {
                if(slow == head)
                    return head;
                    
                slow = slow->next;
            } while(fast != slow);
            
            head = head->next;
        }
    }
};
