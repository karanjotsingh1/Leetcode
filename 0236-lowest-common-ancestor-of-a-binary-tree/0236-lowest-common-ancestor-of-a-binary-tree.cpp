// Approach
// 1. Pehlaa root to p da path store kraange.
// 2. Fer root to q da path store kraange.
// 3. Hun dono paths nu ikathe compare kraange.
// 4. Jadon takk nodes same ne,
//    answer update krde jaavaange.
// 5. Jithe paths different ho jaan,
//    last common node hi LCA houga.
// 6. Ohi node return kr devaange.

/**
 * Definition for a binary tree node.
 * struct TreeNode
 * {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    void root_to_node_path(TreeNode* root,TreeNode* node,vector<TreeNode*>& path,vector<TreeNode*>& final_path)
    {
        if(root==NULL)
        {
            return;
        }

        path.push_back(root);

        if(root==node)
        {
            final_path=path;
            path.pop_back();
            return;
        }

        root_to_node_path(root->left,node,path,final_path);
        root_to_node_path(root->right,node,path,final_path);

        // Backtrack
        path.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        vector<TreeNode*>path1;
        vector<TreeNode*>path2;
        vector<TreeNode*>dummy;

        root_to_node_path(root,p,dummy,path1);
        root_to_node_path(root,q,dummy,path2);

        TreeNode* ans=NULL;

        int i=0;

        while(i<path1.size()&&i<path2.size())
        {
            if(path1[i]!=path2[i])
            {
                break;
            }

            ans=path1[i];
            i++;
        }

        return ans;
    }
};