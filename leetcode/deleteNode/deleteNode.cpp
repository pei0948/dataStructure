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
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
	
	ListNode* deleteNode(ListNode* head, int val) {
        ListNode *curr=head,
                    *pre=nullptr;
        while(curr!=nullptr && curr->val!=val)
        {
            pre=curr;
            curr=curr->next;
        }
        if(curr==nullptr)
        {
            return head;
        }
        if(curr->next==nullptr)
        {
            if(pre==nullptr)
            {
                return nullptr;
            }
            else
            {
                pre->next=nullptr;
            }
        }
        else
        {
            curr->val=curr->next->val;
            curr->next=curr->next->next;
        }
        return head;
    }
};