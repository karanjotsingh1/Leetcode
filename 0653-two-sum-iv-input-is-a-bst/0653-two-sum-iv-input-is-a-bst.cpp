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

    void inorder(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)
            return;

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
        
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
            return false;

        vector<int>ans;
        inorder(root,ans);
        int left=0;
        int right=ans.size()-1;
        while(left<right)
        {
            if(ans[left]+ans[right] == k)
                return true;
            else if(ans[left]+ans[right] < k)
                left+=1;
            else if(ans[left]+ans[right] > k)
                right-=1;
        }
        return false;


    }
};