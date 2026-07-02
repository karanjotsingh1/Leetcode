// Approach
// 1. Pehlaa recursion use kraange.
// 2. Har node lai left te right subtree di height ik hi vaar calculate kraange.
// 3. Je kise subtree already unbalanced hove,
//    ta -1 return kr devaange.
// 4. Je current node te left te right height da difference 1 ton vadda hove,
//    ta -1 return kr devaange.
// 5. Nahi ta current subtree di height return kraange.
// 6. Last ch je root da result -1 hove,
//    ta tree balanced nhi aa.
//    Nahi ta balanced aa.

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

        int left=height(root->left);

        if(left==-1)
        {
            return -1;
        }

        int right=height(root->right);

        if(right==-1)
        {
            return -1;
        }

        if(abs(left-right)>1)
        {
            return -1;
        }

        return 1+max(left,right);
    }

    bool isBalanced(TreeNode* root)
    {
        return height(root)!=-1;
    }
};