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
    ListNode* reverseListIter(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }
        ListNode *pre=NULL;
        ListNode *nextTemp=head->next;
        while(nextTemp)
        {
            head->next=pre;
            pre=head;
            head=nextTemp;
            nextTemp=head->next;
        }
        head->next=pre;
        return head;
    }
        
    ListNode* reverseListRecur(ListNode* head) 
	{
        if(!head || !head->next)
        {
            return head;
        }
        return reverseTwo(NULL, head);
    }
    ListNode *reverseTwo(ListNode *pre, ListNode *curr)
    {
        if(!curr)
        {
            return pre;
        }
        ListNode *nextTemp=curr->next;
        curr->next=pre;
        pre=curr;
        curr=nextTemp;
        return reverseTwo(pre, curr);
    }

};