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
    bool path_sum(TreeNode* root, int targetSum)
    {
        if(root==NULL)
            return false;
        
        if(root->left==NULL && root->right==NULL && root->val==targetSum)
            return true;

        return path_sum(root->left,targetSum-root->val) || path_sum(root->right,targetSum-root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return false;

        

        return path_sum(root,targetSum);

    }
};