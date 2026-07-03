// Approach
// 1. BST di property use kraange.
// 2. Je p te q dono current node ton chhote hon,
//    ta LCA left subtree ch hovega.
// 3. Je p te q dono current node ton vadde hon,
//    ta LCA right subtree ch hovega.
// 4. Je ik node left side te duja right side hove,
//    ya current node hi p ya q hove,
//    ta current node hi Lowest Common Ancestor hovega.
// 5. Recursive approach di jagah iterative approach use kraange,
//    jis naal recursion stack di extra space bach jaavegi.

class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        while(root!=NULL)
        {
            if(root->val>p->val&&root->val>q->val)
            {
                root=root->left;
            }
            else if(root->val<p->val&&root->val<q->val)
            {
                root=root->right;
            }
            else
            {
                return root;
            }
        }

        return NULL;
    }
};