// Approach
// 1. Pehlaa do stacks bnaavaange.
//    Ik current level lai te ik next level lai.
// 2. Even level te first stack process kraange.
//    Left child pehlaa push kraange,
//    fer right child.
// 3. Odd level te second stack process kraange.
//    Right child pehlaa push kraange,
//    fer left child.
// 4. Is order karke next level automatically
//    zigzag order ch traverse houga.
// 5. Har level de values answer ch add kraange.
// 6. Jadon dono stacks empty ho jaan,
//    traversal complete ho jaegi.

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>>ans;

        if(root==NULL)
        {
            return ans;
        }

        stack<TreeNode*>st1;
        stack<TreeNode*>st2;

        st1.push(root);

        int level=0;

        while(!st1.empty()||!st2.empty())
        {
            vector<int>each_level;

            if(level%2==0)
            {
                int size=st1.size();

                for(int i=0;i<size;i++)
                {
                    TreeNode* temp=st1.top();
                    st1.pop();

                    each_level.push_back(temp->val);

                    if(temp->left)
                    {
                        st2.push(temp->left);
                    }

                    if(temp->right)
                    {
                        st2.push(temp->right);
                    }
                }
            }
            else
            {
                int size=st2.size();

                for(int i=0;i<size;i++)
                {
                    TreeNode* temp=st2.top();
                    st2.pop();

                    each_level.push_back(temp->val);

                    if(temp->right)
                    {
                        st1.push(temp->right);
                    }

                    if(temp->left)
                    {
                        st1.push(temp->left);
                    }
                }
            }

            ans.push_back(each_level);
            level++;
        }

        return ans;
    }
};