// Approach
// 1. Pehlaa root de left te right subtree nu compare kraange.
// 2. Je dono nodes NULL hon,
//    ta current mirror part same aa.
// 3. Je ik node NULL hove te dujja na hove,
//    ta tree symmetric nhi aa.
// 4. Je dono nodes di value different hove,
//    ta false return kr devaange.
// 5. Hun mirror comparison kraange.
//    Left subtree da left child,
//    right subtree de right child naal compare houga.
// 6. Fer left subtree da right child,
//    right subtree de left child naal compare houga.
// 7. Je har level te mirror property satisfy hove,
//    ta tree symmetric houga.

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

        return isSameTree(p->left,q->right)&&isSameTree(p->right,q->left);
    }

    bool isSymmetric(TreeNode* root)
    {
        if(root==NULL)
        {
            return true;
        }

        return isSameTree(root->left,root->right);
    }
};