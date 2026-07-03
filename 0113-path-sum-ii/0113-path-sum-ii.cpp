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
    void path_sum_2(TreeNode* root, int targetSum,vector<int>path, vector<vector<int>>&all_paths)
    {
        if(root==NULL)
            return;

        if(root->left==NULL && root->right==NULL && root->val==targetSum)
        {
            path.push_back(root->val);
            all_paths.push_back(path);
            path.pop_back();
            return;
        }
    

        path.push_back(root->val);
        path_sum_2(root->left,targetSum-root->val,path,all_paths);
        path_sum_2(root->right,targetSum-root->val,path,all_paths);
        path.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>all_paths;
        if(root==NULL)  
            return all_paths;

        vector<int>path;
        path_sum_2(root,targetSum,path,all_paths);

        return all_paths;
    }
};