// Approach
// 1. Root ton leaf tak har path da sum check kraange.
// 2. Har node te targetSum cho current node di value subtract kraange.
// 3. Je current node leaf hove,
//    ta check kraange ki remaining targetSum current node di value de equal hai ya nahi.
// 4. Je equal hove,
//    ta valid path mil gaya, true return kar devaange.
// 5. Nahi ta left te right subtree ch recursively search kraange.
// 6. Je kise vi path da sum targetSum de equal hove,
//    ta true return hovega.
// 7. Je koi vi path na mile,
//    ta false return hovega.

class Solution
{
public:
    bool path_sum(TreeNode* root,int targetSum)
    {
        if(root==NULL)
        {
            return false;
        }

        if(root->left==NULL&&root->right==NULL)
        {
            return root->val==targetSum;
        }

        return path_sum(root->left,targetSum-root->val)||path_sum(root->right,targetSum-root->val);
    }

    bool hasPathSum(TreeNode* root,int targetSum)
    {
        return path_sum(root,targetSum);
    }
};