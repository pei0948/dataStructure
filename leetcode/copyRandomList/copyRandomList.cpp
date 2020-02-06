/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
        {
            return NULL;
        }
        Node *curr=head;
        while(curr)
        {
            Node *copy=new Node(curr->val);
            copy->next=curr->next;
            curr->next=copy;
            curr=copy->next;
        }

        curr=head;
        while(curr)
        {
            if(curr->random)
            {
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }

        curr=head;
        Node *result=curr->next;
        while(curr->next)
        {
            Node *n=curr->next;
            curr->next=curr->next->next;
            curr=n;
        }
        return result;
    }
};