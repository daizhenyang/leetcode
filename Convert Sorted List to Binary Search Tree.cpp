/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildBalance(int len)
    {
        if (!len)return NULL;
        int r=len/2;int l=r;
        if (len%2==0)l--;
        TreeNode *p=new TreeNode(0);
        p->left=buildBalance(l);
        p->right=buildBalance(r);
        return p;
    }
    void inorder(TreeNode *p,ListNode * &head)
    {
        if (!p)return;
        inorder(p->left,head);
        p->val=head->val;
        head=head->next;
        inorder(p->right,head);
    }
    TreeNode *sortedListToBST(ListNode * head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ptr=head;
        int len=0;
        while (ptr)
        {
            len++;
            ptr=ptr->next;
        }
        TreeNode *p=buildBalance(len);
        inorder(p,head);
        return p;
    }
};
