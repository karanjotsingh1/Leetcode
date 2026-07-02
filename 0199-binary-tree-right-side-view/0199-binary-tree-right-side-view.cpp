// Approach
// 1. Pehlaa check kraange je tree empty aa,
//    ta empty answer return kr devaange.
// 2. Hun level order traversal(BFS) use kraange.
// 3. Har level de saare nodes queue ch honge.
// 4. Current level de saare nodes process kraange.
// 5. Jadon current level da last node process hove,
//    ohi right side ton visible node houga.
// 6. Onu answer ch add kr devaange.
// 7. Fer current node de left te right child queue ch push kraange.
// 8. Saare levels complete hon to baad answer return kr devaange.

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
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int>ans;

        if(root==NULL)
        {
            return ans;
        }

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int size=q.size();

            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();

                // Last node of the current level
                if(i==size-1)
                {
                    ans.push_back(temp->val);
                }

                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }

                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
            }
        }

        return ans;
    }
};