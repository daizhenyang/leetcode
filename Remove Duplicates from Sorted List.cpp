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
        if (!head)return NULL;
        ListNode *h=head,*p=head,*ptr=head->next;
        while (ptr)
        {
            if (ptr->val!=p->val)
            {
                p->next=ptr;
                p=ptr;
            }
            ptr=ptr->next;
        }
        p->next=NULL;  // I forgot this sentence.
        return h;
    }
};
