/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
struct cmp
{
    bool operator() (ListNode * lhs,  ListNode *rhs) const
    {
        return lhs->val>rhs->val;
    }
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        priority_queue<ListNode *,vector<ListNode *>,cmp>pq;
        for (int i=0;i<lists.size();i++)
        {
            if (lists[i]!=NULL)pq.push(lists[i]);//lists[i]!=NULL
        }
        ListNode *head=NULL,*ptr=NULL;
        while (!pq.empty())
        {
            ListNode *tmp=pq.top();
            pq.pop();
            if (!head)
            {
                head=ptr=tmp;
            }
            else 
            {
                ptr->next=tmp;
                ptr=tmp;
            }
            if (tmp->next)
            {
                pq.push(tmp->next);
            }
        }
        return head;
    }
};
