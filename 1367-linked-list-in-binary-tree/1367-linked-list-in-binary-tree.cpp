// Approach
// 1. Tree de har node nu
//    linked list da possible starting point mannaange.
// 2. Har node te check karaange
//    ki linked list us node ton start ho sakdi hai ya nahi.
// 3. Ik helper DFS function banaavaange,
//    jo current tree node te current linked list node compare karega.
// 4. Je linked list completely traverse ho jaave,
//    matlab poori list match ho gayi,
//    ta true return karaange.
// 5. Je tree node NULL hove
//    ya values match na karan,
//    ta false return karaange.
// 6. Je values match kar jaan,
//    ta linked list de next node nu
//    left child ya right child naal recursively match karaange.
// 7. Je current node ton match na mile,
//    ta tree de left subtree
//    te right subtree ton dubara search start karaange.
// 8. Je kise vi path ton complete linked list match ho jaave,
//    ta true return karaange,
//    nahi ta false.

class Solution
{
public:

    bool matchPath(ListNode* head,TreeNode* root)
    {
        // Entire linked list matched
        if(head==NULL)
        {
            return true;
        }

        // Tree ended
        if(root==NULL)
        {
            return false;
        }

        // Value mismatch
        if(head->val!=root->val)
        {
            return false;
        }

        return matchPath(head->next,root->left) || matchPath(head->next,root->right);
    }

    bool isSubPath(ListNode* head,TreeNode* root)
    {
        if(root==NULL)
        {
            return false;
        }

        // Try starting from current node
        if(matchPath(head,root))
        {
            return true;
        }

        // Try left subtree or right subtree
        return isSubPath(head,root->left) ||isSubPath(head,root->right);
    }
};