/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root,string path,vector<string>&ans)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            path+=to_string(root->val);
            ans.push_back(path);
            return;
        }

        path=path+to_string(root->val)+"->";
        traverse(root->left,path,ans);
        traverse(root->right,path,ans);
        return;

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(root==NULL)
        {
            return ans;
        }
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(to_string(root->val));
            return ans;
        }

        string path="";
        traverse(root,path,ans);
        return ans;
    }
};