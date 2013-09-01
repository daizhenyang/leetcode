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
TreeNode *buildTree(vector<int> &postorder, vector<int> &inorder,int l1,int r1,int l2,int r2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (l1>r1||l2>r2||r1>=postorder.size()||r2>=inorder.size())return NULL;
        TreeNode *p=new TreeNode(postorder[r1]);
        int i;
        for (i=l2;i<=r2;i++)
        {
            if (inorder[i]==postorder[r1])break;
        }
        p->left=buildTree(postorder,inorder,l1,l1+i-l2-1,l2,i-1);
        p->right=buildTree(postorder,inorder,l1+i-l2,r1-1,i+1,r2);
        return p;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (inorder.empty())return NULL;
        return buildTree(postorder,inorder,0,postorder.size()-1,0,inorder.size()-1);
    }
};
