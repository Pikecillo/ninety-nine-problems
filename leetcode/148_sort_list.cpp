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

    ListNode* merge(ListNode *head1, ListNode *head2) {
        if(head1 == nullptr)
            return head2;
        if(head2 == nullptr)
            return head1;
        
        ListNode *lo1 = head1, *lo2 = head2;
        ListNode *head = head1;
        
        if(head1->val > head2->val) {
            head = head2;
            head2 = head2->next;
        }
        else {
            head1 = head1->next;
        }
            
        ListNode *curr = head;
        
        while(head1 != nullptr && head2 != nullptr) {
            curr->next = head1;
            
            if(head1->val > head2->val) {
                curr->next = head2;
                head2 = head2->next;
            }
            else {
                head1 = head1->next;
            }
            
            curr = curr->next;
        }
        
        if(head1 != nullptr)
            curr->next = head1;
        if(head2 != nullptr)
            curr->next = head2;
        
        return head;
    }

    void split(ListNode *head, ListNode *&head1, ListNode *&head2) {
        if(head == nullptr) {
            head1 = head2 = nullptr;
            return;
        }
        if(head->next == nullptr) {
            head1 = head;
            head2 = nullptr;
            return;
        }
        
        ListNode *node = head;
        int n = 0;
        
        while(node != nullptr) {
            node = node->next;
            n++;
        }
        
        head1 = head2 = head;
        
        n /= 2;
        
        while(n--) {
            ListNode *node = head2;
            head2 = head2->next;
            
            if(n == 0) {
                node->next = nullptr;    
            }
        }
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        if(head->next->next == nullptr) {
            ListNode *head1 = head;
            ListNode *head2 = head->next;
            
            if(head1->val > head2->val) {
                std::swap(head1->val, head2->val);
            }
            
            return head1;
        }
        
        ListNode *head1, *head2;
        
        split(head, head1, head2);
        
        head1 = sortList(head1);
        head2 = sortList(head2);
        
        return merge(head1, head2);
    }
};
