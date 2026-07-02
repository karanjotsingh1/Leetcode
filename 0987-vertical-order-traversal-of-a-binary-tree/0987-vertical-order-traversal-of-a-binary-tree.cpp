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

    void diamter_of_BT(TreeNode* root,int &left,int &ryt,int curr)
    {
        if(root==NULL)
            return;

        left=min(left,curr);
        ryt=max(ryt,curr);
        diamter_of_BT(root->left,left,ryt,curr-1);
        diamter_of_BT(root->right,left,ryt,curr+1);
    }

    void vertical(TreeNode* root,vector<vector<pair<int,int>>>&ans,int left,int curr,int level)
    {
        if(root==NULL)
            return;
        
        ans[curr+left].push_back({level,root->val});

        vertical(root->left,ans,left,curr-1,level+1);
        vertical(root->right,ans,left,curr+1,level+1);
    }


    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int left=0;
        int right=0;
        int curr=0;
        diamter_of_BT(root,left,right,curr);
        
        vector<vector<pair<int,int>>>ans(right-left+1);
        vector<vector<int>>main_ans(right-left+1);

        left=left*-1;
        curr=0;
        int level=0;
        vertical(root,ans,left,curr,level);

        
        for(int i=0;i<ans.size();i++)
        {
             sort(ans[i].begin(), ans[i].end());
             for(int j=0;j<ans[i].size();j++)
             {
                main_ans[i].push_back(ans[i][j].second);
             }
        }
        return main_ans;

    }
};