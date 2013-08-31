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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ptr=head,*pre;
        int len=0;
        while (ptr)
        {
            ++len;
            ptr=ptr->next;
        }
        if (!len)return head;//forgot to judge oringinal list is NULL
        k%=len;
        if (!k)return head;
        int c=len-k;
        pre=ptr=head;
        while (c--)
        {
            pre=ptr;
            ptr=ptr->next;
        }
        pre->next=NULL;
        ListNode *ed=ptr;
        while (ed)
        {
            pre=ed;
            ed=ed->next;
        }
        pre->next=head;
        return ptr;
    }
};
