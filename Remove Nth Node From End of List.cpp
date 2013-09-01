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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p1=head,*p2=head,*pre;
        int c=n;
        while (c--)p2=p2->next;
        if (!p2)
        {
            ListNode *tmp=head;
            head=head->next;
            delete tmp;
            return head;
        }
        while (p2)
        {
            pre=p1;
            p1=p1->next;
            p2=p2->next;
        }
        ListNode *tmp=p1;
        pre->next=p1->next;
        delete tmp;
        return head;
    }
};
