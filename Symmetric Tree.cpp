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
    bool symmetry(TreeNode *l,TreeNode *r)
    {
        if (!l&&!r)return 1;
        if (!l||!r)return 0;
        if (l->val!=r->val)return 0;
        return symmetry(l->left,r->right)&&symmetry(l->right,r->left);
    }
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)return 1;
        return symmetry(root->left,root->right);
    }
};
