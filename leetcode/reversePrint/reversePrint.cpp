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
    vector<int> reversePrint(ListNode* head) {
        if(head==nullptr)
        {
            return {};
        }
        ListNode *node=head;
        int cnt=0;
        while(node!=nullptr)
        {
            ++cnt;
            node=node->next;
        }
        vector<int> res(cnt, 0);
        --cnt;
        node=head;
        while(cnt>=0)
        {
            res[cnt]=node->val;
            --cnt;
            node=node->next;
        }
        return res;
    }
};