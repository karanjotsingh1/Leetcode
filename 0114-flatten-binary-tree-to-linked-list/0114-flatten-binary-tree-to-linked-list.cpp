// Approach
// 1. Pehlaa reverse preorder traversal use kraange.
//    Order houga: Right -> Left -> Root.
// 2. Ik prev pointer maintain kraange,
//    jo pehlaa processed node nu point krda houga.
// 3. Sab ton pehlaa right subtree flatten kraange.
// 4. Fer left subtree flatten kraange.
// 5. Hun current node da right prev naal connect kraange.
// 6. Left pointer NULL kr devaange,
//    kyunki linked list ch left child nhi hunda.
// 7. Current node nu prev bna devaange.
// 8. Recursion complete hon to baad,
//    poora tree preorder linked list ch convert ho jaega.

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
    TreeNode* prev=NULL;

    void flatten(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }

        flatten(root->right);
        flatten(root->left);

        root->right=prev;
        root->left=NULL;

        prev=root;
    }
};