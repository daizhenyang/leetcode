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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)return vector<vector<int> >();
        queue<TreeNode *>q;
        q.push(root);
        int node_in_now_level=1;
        int node_in_next_level=0;
        vector<vector<int> >ans;
        vector<int>now;
        while (!q.empty())
        {
            TreeNode *p=q.front();
            q.pop();
            now.push_back(p->val);
            node_in_now_level--;
            if (p->left)
            {
                q.push(p->left);
                node_in_next_level++;
            }
            if (p->right)
            {
                q.push(p->right);
                node_in_next_level++;
            }
            if (!node_in_now_level)
            {
                ans.push_back(now);
                now.clear();
                swap(node_in_now_level,node_in_next_level);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
