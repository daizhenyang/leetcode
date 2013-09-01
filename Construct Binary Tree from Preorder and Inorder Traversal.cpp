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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder,int l1,int r1,int l2,int r2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (l1>r1||l2>r2||r1>=preorder.size()||r2>=inorder.size())return NULL;
        TreeNode *p=new TreeNode(preorder[l1]);
        int i;
        for (i=l2;i<=r2;i++)
        {
            if (inorder[i]==preorder[l1])break;
        }
        p->left=buildTree(preorder,inorder,l1+1,l1+i-l2,l2,i);
        p->right=buildTree(preorder,inorder,l1+1+i-l2,r1,i+1,r2);
        return p;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (preorder.empty())return NULL;
        return buildTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};
