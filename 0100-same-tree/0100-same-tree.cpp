// Approach
// 1. Pehlaa check kraange je dono nodes NULL ne,
//    ta trees is point tak same ne, true return kr devaange.
// 2. Je ik node NULL hove te dujja na hove,
//    ta trees different ne, false return kr devaange.
// 3. Je dono nodes di value different hove,
//    ta false return kr devaange.
// 4. Nahi ta recursively left subtree compare kraange.
// 5. Fer recursively right subtree compare kraange.
// 6. Je left te right dono same hon,
//    ta current subtree vi same hougi.

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
    bool isSameTree(TreeNode* p,TreeNode* q)
    {
        if(p==NULL&&q==NULL)
        {
            return true;
        }

        if((p==NULL&&q!=NULL)||(p!=NULL&&q==NULL))
        {
            return false;
        }

        if(p->val!=q->val)
        {
            return false;
        }

        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};