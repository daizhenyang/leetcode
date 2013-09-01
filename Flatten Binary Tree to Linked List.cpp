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
    TreeNode *pre;
    void preorder(TreeNode *r)
    {
        if (!r)return;
        if (pre)
        {
            pre->right=r;
            pre->left=NULL;
        }
        pre=r;
        TreeNode *left=r->left,*right=r->right;
        preorder(left);
        preorder(right);
    }
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        pre=NULL;
        preorder(root);
    }
};
