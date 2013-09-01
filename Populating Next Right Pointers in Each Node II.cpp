/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)return;
        queue<TreeLinkNode *>q;
        q.push(root);
        int node_in_now_level=1;
        int node_in_next_level=0;
        TreeLinkNode *last=NULL;
        while (!q.empty())
        {
            TreeLinkNode *t=q.front();
            q.pop();
            if (last)last->next=t;
            node_in_now_level--;
            if (t->left)
            {
                node_in_next_level++;
                q.push(t->left);
            }
            if (t->right)
            {
                node_in_next_level++;
                q.push(t->right);
            }
            if (!node_in_now_level)
            {
                last=NULL;
                swap(node_in_now_level,node_in_next_level);
            }
            else 
            {
                last=t;
            }
        }
    }
};
