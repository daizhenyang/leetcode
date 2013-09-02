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
    int ans;
    void dfs(TreeNode *r,int val)
    {
        if (!r)return;
        if (!r->left&&!r->right)
        {
            ans+=val;
            return;
        }
        if (r->left)dfs(r->left,val*10+r->left->val);
        if (r->right)dfs(r->right,val*10+r->right->val);
    }
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)return 0;
        ans=0;
        dfs(root,root->val);
        return ans;
    }
};
