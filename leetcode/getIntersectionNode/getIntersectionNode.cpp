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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
        {
            return NULL;
        }
        int lenA=0,lenB=0;
        ListNode *tmpA=headA;
        ListNode *tmpB=headB;
        while(tmpA)
        {
            lenA++;
            tmpA=tmpA->next;
        }
        while(tmpB)
        {
            lenB++;
            tmpB=tmpB->next;
        }
        tmpA=headA;
        tmpB=headB;
        int diffLen;
        if(lenA>lenB)
        {
            diffLen=lenA-lenB;
            while(diffLen)
            {
                tmpA=tmpA->next;
                diffLen--;
            }
        }
        else if(lenA<lenB)
        {
            diffLen=lenB-lenA;
            while(diffLen)
            {
                tmpB=tmpB->next;
                diffLen--;
            }
        }
        while(tmpA!=tmpB)
        {
            tmpA=tmpA->next;
            tmpB=tmpB->next;
        }
        return tmpA;
    }
};