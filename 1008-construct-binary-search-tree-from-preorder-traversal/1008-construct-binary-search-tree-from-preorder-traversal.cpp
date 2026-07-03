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
    TreeNode* make_bst(vector<int>& pre,vector<int>& nge,int n,int start_ptr,int end_ptr)
    {
        if(start_ptr>end_ptr)
            return NULL;

        TreeNode* node=new TreeNode(pre[start_ptr]);

        node->left=make_bst(pre,nge,n,start_ptr+1,nge[start_ptr]-1);
        node->right=make_bst(pre,nge,n,nge[start_ptr],end_ptr);

        return node;
        
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int n=pre.size();
        if(n==0)
            return NULL;

        vector<int>nge(n,n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(st.empty()==false && pre[st.top()]<pre[i])
            {
                nge[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }

        int start_ptr=0;
        int end_ptr=n-1;
        TreeNode* root=make_bst(pre,nge,n,start_ptr,end_ptr);

        return root;
    }
};