// Approach
// 1. Pehlaa recursion use kraange.
// 2. Je current node NULL hove,
//    ta height 0 return kr devaange.
// 3. Left subtree di height recursively calculate kraange.
// 4. Right subtree di height recursively calculate kraange.
// 5. Current node di height,
//    left te right subtree di maximum height + 1 hougi.
// 6. Root di height hi tree di maximum depth hougi.

/**
 * Definition for a binary tree node.
 * struct TreeNode
 * {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x,TreeNode *left,TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }

        return 1+max(height(root->left),height(root->right));
    }

    int maxDepth(TreeNode* root)
    {
        return height(root);
    }
};