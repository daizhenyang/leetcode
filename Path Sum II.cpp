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
    vector<vector<int> >ans;
    void dfs(TreeNode *r,int t,vector<int>a)
    {
        if (!r)return;
        if (!r->left&&!r->right)
        {
            if (!t)ans.push_back(a);
            return;
        }
        if (r->left)
        {
            a.push_back(r->left->val);
            dfs(r->left,t-r->left->val,a);
            a.pop_back();
        }
        if (r->right)
        {
            a.push_back(r->right->val);
            dfs(r->right,t-r->right->val,a);
            a.pop_back();
        }
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)return vector<vector<int> >();
        vector<int>a;
        a.push_back(root->val);
        ans.clear();
        dfs(root,sum-root->val,a);
        return ans;
    }
};
