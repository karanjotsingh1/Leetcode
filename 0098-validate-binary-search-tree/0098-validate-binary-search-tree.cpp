// Approach
// 1. Har node lai ik valid range maintain kraange.
// 2. Initially root di range (-infinity,+infinity) hovegi.
// 3. Je current node di value range de bahar hove,
//    ta BST valid nahi hai.
// 4. Left child lai maximum value current node di value ban jaavegi.
// 5. Right child lai minimum value current node di value ban jaavegi.
// 6. Recursively left te right subtree check kraange.
// 7. Je saare nodes apni valid range ch aa jaan,
//    ta BST valid hai.

class Solution
{
public:
    bool solve(TreeNode* root,long long low,long long high)
    {
        if(root==NULL)
        {
            return true;
        }

        if(root->val<=low||root->val>=high)
        {
            return false;
        }

        return solve(root->left,low,root->val) && solve(root->right,root->val,high);
    }

    bool isValidBST(TreeNode* root)
    {
        return solve(root,LLONG_MIN,LLONG_MAX);
    }
};