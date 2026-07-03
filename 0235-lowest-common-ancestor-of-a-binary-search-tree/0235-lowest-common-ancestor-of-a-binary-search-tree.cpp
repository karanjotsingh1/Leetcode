/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL)
            return NULL;

        if((root->val > p->val && root->val < q->val) || (root->val < p->val && root->val > q->val))
            return root;

        if(root->val > p->val && root->val > q->val)
            return LCA(root->left,p,q);

        if(root->val < p->val && root->val < q->val)
            return LCA(root->right,p,q);

        return root;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL ||p==NULL || q==NULL)
            return NULL;

        return LCA(root,p,q);

        
    }
};