// Approach
// 1. Pehlaa DFS use krke minimum te maximum horizontal distance find kraange.
// 2. Horizontal range miln to baad,
//    ona size da answer vector bnaavaange.
// 3. Hun dubara DFS kraange.
//    Har node nu usdi horizontal distance de according store kraange.
//    Pair(level,value) store kraange taaki baad ch sorting ho sake.
// 4. Har vertical column nu sort kraange.
//    Pair automatic pehlaa level te fer value de basis te sort hunda aa.
// 5. Sorted values nu final answer ch copy kr devaange.
// 6. Last ch vertical traversal return kr devaange.

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
    void findHorizontalRange(TreeNode* root,int& left,int& right,int col)
    {
        if(root==NULL)
        {
            return;
        }

        left=min(left,col);
        right=max(right,col);

        findHorizontalRange(root->left,left,right,col-1);
        findHorizontalRange(root->right,left,right,col+1);
    }

    void vertical(TreeNode* root,vector<vector<pair<int,int>>>& ans,int offset,int col,int level)
    {
        if(root==NULL)
        {
            return;
        }

        ans[col+offset].push_back({level,root->val});

        vertical(root->left,ans,offset,col-1,level+1);
        vertical(root->right,ans,offset,col+1,level+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        int left=0;
        int right=0;

        findHorizontalRange(root,left,right,0);

        vector<vector<pair<int,int>>>temp(right-left+1);
        vector<vector<int>>ans(right-left+1);

        int offset=-left;

        vertical(root,temp,offset,0,0);

        for(int i=0;i<temp.size();i++)
        {
            sort(temp[i].begin(),temp[i].end());

            for(int j=0;j<temp[i].size();j++)
            {
                ans[i].push_back(temp[i][j].second);
            }
        }

        return ans;
    }
};