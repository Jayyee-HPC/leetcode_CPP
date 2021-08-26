//First attempt: two pointers
//TEST: 7 ms faster than 22.12%, 10.8 MB mem.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {                
        ListNode* s = head;
        ListNode* f = head;
        
        int c = 0;
        
        while(c < n)
        {
            if(!f->next)
                return s->next;
            
            f = f->next;
            c++;
        }
        
        while(f->next != NULL)
        {
            s = s->next;
            f = f->next;
        }
        
        if(s->next != NULL)
            s->next = s->next->next;
        
        return head;
    }
};