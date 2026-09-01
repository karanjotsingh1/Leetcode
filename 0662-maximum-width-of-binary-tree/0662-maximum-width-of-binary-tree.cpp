class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }

        if(root->left==NULL && root->right==NULL)
        {
            return 1;
        }

        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});

        int ans=0;

        while(q.empty()==false)
        {
            int n=q.size();

            long long first=q.front().second;
            long long idx1=0;
            long long idx2=0;

            for(int i=1;i<=n;i++)
            {
                TreeNode* temp=q.front().first;
                long long idx=q.front().second;

                q.pop();

                idx=idx-first;

                if(i==1)
                {
                    idx1=idx;
                }

                if(i==n)
                {
                    idx2=idx;
                }

                if(temp->left)
                {
                    q.push({temp->left,idx*2});
                }

                if(temp->right)
                {
                    q.push({temp->right,idx*2+1});
                }
            }

            ans=max(ans,(int)(idx2-idx1+1));
        }

        return ans;
    }
};