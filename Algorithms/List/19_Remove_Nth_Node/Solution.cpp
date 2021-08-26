//First attempt: use a vector record all nodes
//TEST: 13 ms faster than 22.12%, 10.9 MB mem.

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
        if (!head)
            return NULL;
        
        vector<ListNode*> vect_nodes;
        
        ListNode* curser = head;
        
        while (curser != NULL)
        {
            vect_nodes.push_back(curser);
            
            curser = curser->next;
        }
        
        if (n == vect_nodes.size())
        {
            return head->next;
        }
        else
        {
            curser = head;
            int target = vect_nodes.size() - n;
            for (int i = 1; i < vect_nodes.size(); ++i)
            {
                if (i == target)
                {
                    if (i == vect_nodes.size() - 1)
                        curser->next = NULL;
                    
                    continue;
                }
                    
                
                curser->next = vect_nodes[i];
                
                curser = curser->next;
            }
            
        }
        
        return head;
    }
};