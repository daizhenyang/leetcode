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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *h=NULL,*ptr=NULL,*p=head;
        ListNode *h1=NULL,*ptr1=NULL;
        while (p)
        {
            if (p->val<x)
            {
                if (!h)h=ptr=p;
                else 
                {
                    ptr->next=p;
                    ptr=p;
                }
            }
            else 
            {
                if (!h1)h1=ptr1=p;
                else 
                {
                    ptr1->next=p;
                    ptr1=p;
                }
            }
            p=p->next;
        }
        if (ptr1)ptr1->next=NULL;
        if (ptr)ptr->next=h1;
        else h=h1;
        return h;
    }
};
