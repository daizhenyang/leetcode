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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ptr=head,*rt=head,*lst;
        while (ptr)
        {
            ListNode *nxt=ptr->next;
            if (!nxt)break;
            ListNode *tmp=nxt->next;
            ptr->next=tmp;
            nxt->next=ptr;
            if (rt==head)rt=nxt;
            else lst->next=nxt;
            lst=ptr;
            ptr=ptr->next;
        }
        return rt;
    }
};
