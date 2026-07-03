// Approach
// 1. Tree nu DFS naal traverse kraange.
// 2. Har node te check kraange ki (k-current value) pehla visit hoya hai ya nahi.
// 3. Je HashSet ch mil jaave,
//    ta do nodes da sum k de equal hai.
// 4. Je na mile,
//    ta current value HashSet ch store kar devaange.
// 5. Fir left te right subtree recursively traverse kraange.
// 6. Je poori traversal ch pair na mile,
//    ta false return kar devaange.

class Solution
{
public:
    unordered_set<int>st;

    bool solve(TreeNode* root,int k)
    {
        if(root==NULL)
        {
            return false;
        }

        if(st.find(k-root->val)!=st.end())
        {
            return true;
        }

        st.insert(root->val);

        return solve(root->left,k)||solve(root->right,k);
    }

    bool findTarget(TreeNode* root,int k)
    {
        return solve(root,k);
    }
};