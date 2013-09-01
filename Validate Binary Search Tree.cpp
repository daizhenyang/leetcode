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
    pair<pair<int,int>,bool>judge(TreeNode *root)
    {
        int mx=root->val;
        int mi=mx;
        bool r=true;
        pair<pair<int,int>,bool>pl,pr;
        if (root->left)
        {
            pl=judge(root->left);
            mx=max(mx,pl.first.first);
            mi=min(mi,pl.first.second);
            r&=pl.second;
            if (pl.first.first>=root->val)r=false;
        }
        if (root->right)
        {
            pr=judge(root->right);
            mx=max(mx,pr.first.first);
            mi=min(mi,pr.first.second);
            r&=pr.second;
            if (pr.first.second<=root->val)r=false;
        }      
        return make_pair(make_pair(mx,mi),r);
    }
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)return true;
        return judge(root).second;
    }
};
