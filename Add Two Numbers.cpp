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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *h=l1,*p1,*p2;
        int carry=0;
        while (l1&&l2)
        {
            l1->val=l1->val+l2->val+carry;
            carry=l1->val>9;
            l1->val%=10;
            p1=l1;p2=l2;
            l1=l1->next;
            l2=l2->next;
        }
        if (!l1&&!l2&&carry)
        {
            p1->next=new ListNode(1);
        }
        if (l1)
        {
            while (l1)
            {
                l1->val=l1->val+carry;
                carry=l1->val>9;
                l1->val%=10;
                p1=l1;
                l1=l1->next;
            }
            if (carry)
            {
                p1->next=new ListNode(1);
            }
        }
        else if (l2)
        {
            p1->next=l2;
            while (l2)
            {
                l2->val=l2->val+carry;
                carry=l2->val>9;
                l2->val%=10;
                p2=l2;
                l2=l2->next;
            }
            if (carry)
            {
                p2->next=new ListNode(1);
            }
        }
        return h;
    }
};
