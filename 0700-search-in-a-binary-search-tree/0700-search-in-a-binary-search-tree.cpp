// Approach
// 1. Je root NULL hove ta matlab value tree ch exist nahi kardi,
//    ta NULL return kar devaange.
// 2. BST di property use kraange.
// 3. Je current node di value target de equal hove,
//    ta ohi node return kar devaange.
// 4. Je target value current node ton chhoti hove,
//    ta left subtree ch search kraange.
// 5. Je target value current node ton vaddi hove,
//    ta right subtree ch search kraange.
// 6. Recursive calls di jagah iterative approach use kraange,
//    jis naal recursion stack di extra space bach jaavegi.

class Solution
{
public:
    TreeNode* searchBST(TreeNode* root,int val)
    {
        while(root!=NULL)
        {
            if(root->val==val)
            {
                return root;
            }

            if(val<root->val)
            {
                root=root->left;
            }
            else
            {
                root=root->right;
            }
        }

        return NULL;
    }
};