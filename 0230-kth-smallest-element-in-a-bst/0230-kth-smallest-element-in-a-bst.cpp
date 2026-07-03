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
    void k_smallest(TreeNode* root, int &k, int &smallest)
    {
        if(root==NULL)
            return;
        
        k_smallest(root->left,k,smallest);
        k--;
        if(k==0)
        {
            smallest=min(smallest,root->val);
            return;
        }
        k_smallest(root->right,k,smallest);

    }
    int kthSmallest(TreeNode* root, int k) {
        int smallest=INT_MAX;
        k_smallest(root,k,smallest);
        return smallest;
    }
};