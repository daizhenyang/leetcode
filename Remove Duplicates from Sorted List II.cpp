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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *h=NULL,*t=NULL;
        if (!head)return NULL;
        ListNode *ptr=head,*pre=NULL;
        while (ptr)
        {
            if ((!pre||pre->val!=ptr->val)&&(!ptr->next||ptr->next->val!=ptr->val))
            {
                if (!h)h=t=ptr;
                else 
                {
                    t->next=ptr;
                    t=ptr;
                }
            }
            pre=ptr;
            ptr=ptr->next;
        }
        if (t)t->next=NULL;  //forgot if (t)
        return h;
    }
};
