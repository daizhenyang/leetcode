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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p1=l1,*p2=l2;
        ListNode *head=NULL,*ptr=NULL;
        while (p1&&p2)
        {
            if (p1->val<p2->val)
            {
                if (!head)
                {
                    head=ptr=p1;
                }
                else 
                {
                    ptr->next=p1;
                    ptr=p1;
                }
                p1=p1->next;
            }
            else 
            {
                if (!head)
                {
                    head=ptr=p2;
                }
                else 
                {
                    ptr->next=p2;
                    ptr=p2;
                }
                p2=p2->next;
            }
        }
        while (p1)
        {
            if (!head)
            {
                head=ptr=p1;
            }
            else 
            {
                ptr->next=p1;
                ptr=p1;
            }
            p1=p1->next;
        }
        while (p2)
        {
            if (!head)
            {
                head=ptr=p2;
            }
            else 
            {
                ptr->next=p2;
                ptr=p2;
            }
            p2=p2->next;
        }
        return head;
    }
};
