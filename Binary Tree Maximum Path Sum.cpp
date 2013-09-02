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
    int dfs(TreeNode *r)
    {
        int mx=0,x=r->val;
        if (r->left)
        {
            int z=dfs(r->left);
            mx=max(mx,z);
            x+=z;
        }
        if (r->right)
        {
            int z=dfs(r->right);
            mx=max(mx,z);
            x+=z;
        }
        ans=max(ans,r->val+mx);
        ans=max(ans,x);
        return r->val+mx;
    }
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)return 0;
        ans=root->val;
        dfs(root);
        return ans;
    }
};
