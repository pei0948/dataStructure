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
    bool isPalindrome(ListNode* head) {
        if((!head) || (!(head->next)))
        {
            return true;
        }
        stack<int> s;
        int len=0;
        ListNode *temp=head;
        while(temp)
        {
            s.push(temp->val);
            temp=temp->next;
            len++;
        }
        len=len/2;
        for(int i=0; i<len; i++)
        {
            if(s.top()!=head->val)
            {
                return false;
            }
            s.pop();
            head=head->next;
        }
        return true;
    }
};