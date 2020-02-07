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
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
    ListNode *mergeSort(ListNode *head)
    {
        if((!head) || !(head->next))
        {
            return head;
        }
        ListNode *slow=head,
                    *fast=head->next->next;

        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        } 

        ListNode *right=mergeSort(slow->next);
        slow->next=NULL;
        ListNode *left=mergeSort(head);
        return merge(left, right);
    }
    ListNode *merge(ListNode *left, ListNode *right)
    {
        ListNode *tmpHead=new ListNode(-1);
        ListNode *curr=tmpHead;
        while(left && right)
        {
            if(left->val > right->val)
            {
                curr->next=right;
                right=right->next;
            }
            else{
                curr->next=left;
                left=left->next;
            }
            curr=curr->next;
        }
        if(left)
        {
            curr->next=left;
        }
        else
        {
            curr->next=right;
        }
        return tmpHead->next;
    }
};