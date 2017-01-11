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
    void reorderList(ListNode* head) {
        if(!head)
            return;
        
        vector<ListNode *> nodes;
        
        while(head != nullptr) {
            nodes.push_back(head);
            head = head->next;
        }
        
        auto front = nodes.begin(), back = nodes.end();
        
        while(distance(front, back) > 1) {
            (*front)->next = *(--back);
            (*back)->next = *(++front);
        }
        
        (*front)->next = nullptr;
    }
};
