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
    TreeNode *convert(vector<int> &num,int l,int r)
    {
        if (l>r)return NULL;
        int mid=(l+r)/2;
        TreeNode *p=new TreeNode(num[mid]);
        p->left=convert(num,l,mid-1);
        p->right=convert(num,mid+1,r);
        return p;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return convert(num,0,(int)num.size()-1);
    }
};
