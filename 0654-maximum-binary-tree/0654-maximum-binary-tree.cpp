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
    int maxi_in_array(vector<int>& nums,int left, int ryt)
    {
        int maxi=-1;
        int idx=-1;
        for(int i=left;i<=ryt;i++)
        {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
                idx=i;
            }
        }
        return idx;
    }
    TreeNode* construct_BT(vector<int>& nums,int left, int ryt,int &n)
    {
        if(left>ryt || left<0 ||left>=n || ryt<0 ||ryt>=n)
            return NULL;

        int idx=maxi_in_array(nums,left,ryt);

        TreeNode* root=new TreeNode(nums[idx]);

        root->left=construct_BT(nums,left,idx-1,n);
        root->right=construct_BT(nums,idx+1,ryt,n);

        return root;
        
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        int n=nums.size();
        int left=0;
        int ryt=nums.size()-1;
        return construct_BT(nums,left,ryt,n);
    }
};