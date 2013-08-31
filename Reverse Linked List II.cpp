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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ptr=head,*f,*t,*h;
        if (m>n)swap(m,n);
        if (m==n)return head;
        int now=0;
        ListNode *pre=NULL;
        while (ptr)
        {
            ++now;
            if (now==m-1)h=ptr;
            if (now>=m&&now<=n)
            {
                if (now==m)f=ptr;
                if (now==n)t=ptr;
                ListNode *nxt=ptr->next;
                ptr->next=pre;
                pre=ptr;
                ptr=nxt;
            }
            if (now==n+1||now==n&&!ptr)
            {
                f->next=ptr;
                if (m>1)h->next=t;
                else head=t;
            }
            if (now<m||now>n)ptr=ptr->next;
        }
        return head;
    }
};
