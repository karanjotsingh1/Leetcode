/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int heigth(TreeNode* root,int depth)
    {
        if(root==NULL)
            return 0;

        return 1+max(heigth(root->left,depth+1),heigth(root->right,depth+1));
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;

        int depth=1;
        return heigth(root,depth);
    }
};