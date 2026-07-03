// Approach
// 1. Preorder da pehla element hamesha current subtree da root hunda hai.
// 2. Har element lai Next Greater Element (NGE) find kraange.
// 3. NGE da index dassda hai ki left subtree kithe khatam hundi hai
//    te right subtree kitthon start hundi hai.
// 4. Root banaun to baad start_ptr+1 ton NGE-1 tak left subtree banaange.
// 5. NGE ton end_ptr tak right subtree recursively banaange.
// 6. Je start_ptr end_ptr ton vadda ho jaave,
//    ta NULL return kar devaange.
// 7. Is tarah bina preorder nu dubara search kite poori BST build ho jaavegi.

class Solution
{
public:
    TreeNode* make_bst(vector<int>& pre,vector<int>& nge,int start_ptr,int end_ptr)
    {
        if(start_ptr>end_ptr)
        {
            return NULL;
        }

        TreeNode* node=new TreeNode(pre[start_ptr]);

        node->left=make_bst(pre,nge,start_ptr+1,nge[start_ptr]-1);

        node->right=make_bst(pre,nge,nge[start_ptr],end_ptr);

        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& pre)
    {
        int n=pre.size();

        if(n==0)
        {
            return NULL;
        }

        vector<int>nge(n,n);
        stack<int>st;

        for(int i=0;i<n;i++)
        {
            while(st.empty()==false&&pre[st.top()]<pre[i])
            {
                nge[st.top()]=i;
                st.pop();
            }

            st.push(i);
        }

        return make_bst(pre,nge,0,n-1);
    }
};