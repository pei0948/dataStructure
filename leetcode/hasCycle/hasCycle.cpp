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
    bool hasCycle1(ListNode *head) {
        if(!head)
        {
            return false;
        }
        int pos=0;
        map<ListNode *, int> m;
        m[head]=pos;
        ListNode *curr=head->next;
        while(curr)
        {
            if(m.count(curr))
            {
                return true;
            }
            else
            {
                pos=pos+1;
                m[curr]=pos;
                curr=curr->next;
            }
        }
        return false;
    }
	bool hasCycle2(ListNode *head) {
        if(!head)
        {
            return false;
        }
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                return true;
            }
        }
        return false;
    }
};