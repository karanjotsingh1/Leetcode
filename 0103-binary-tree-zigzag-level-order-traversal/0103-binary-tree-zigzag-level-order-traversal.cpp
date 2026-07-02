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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;

        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        st1.push(root);
        int level=0;
        while(st1.empty()==false || st2.empty()==false)
        {
            int n;
            if(level%2==0)
                n=st1.size();
            else
                n=st2.size();

            vector<int>each_level;

            for(int i=1;i<=n;i++)
            {
                TreeNode* temp;
                if(level%2==0)
                {
                    temp=st1.top();
                    st1.pop();

                    each_level.push_back(temp->val);

                    if(temp->left)
                        st2.push(temp->left);
                    if(temp->right)
                        st2.push(temp->right);


                }
                else
                {
                    temp=st2.top();
                    st2.pop();

                    each_level.push_back(temp->val);

                    if(temp->right)
                        st1.push(temp->right);
                    if(temp->left)
                        st1.push(temp->left);
                    
                }

            }
            level++;
            ans.push_back(each_level);
        }
        return ans;
    }
};