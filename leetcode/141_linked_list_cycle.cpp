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
    bool hasCycle(ListNode *head) {
        ListNode *node1 = head, *node2 = head;
        
        while(node1 && node2) {
            node1 = node1->next;
            
            if(node1 == node2)
                return true;
                
            node2 = node2->next;
            
            if(node1)
                node1 = node1->next;
        }
        
        return false;
    }
};
