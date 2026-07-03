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
    TreeNode* make_bst(vector<int>& nums,int first,int last)
    {
        if(first>last)
            return NULL;
        int mid=first+((last-first)/2);
        int ele=nums[mid];

        TreeNode* node=new TreeNode(ele);

        node->left=make_bst(nums,first,mid-1);
        node->right=make_bst(nums,mid+1,last);

        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();

        int first=0;
        int last=n-1;
        TreeNode* root=make_bst(nums,first,last);
        return root;
    }
};