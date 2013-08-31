//solve by recursion

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
    ListNode *reverse(ListNode *head)
    {
        ListNode *ptr=head,*tmp=NULL;
        while (ptr)
        {
            ListNode *nxt=ptr->next;
            ptr->next=tmp;
            tmp=ptr;
            ptr=nxt;
        }
        return tmp;
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head==NULL)return head;
        ListNode *ptr=head;
        int c=k;
        while (--c&&ptr)
        {
            ptr=ptr->next;
        }
        if (!ptr)return head;
        ListNode *nxt=ptr->next,*tmp=head;
        ptr->next=NULL;
        head=reverse(head);
        tmp->next=reverseKGroup(nxt,k);
        return head;
        
    }
};
