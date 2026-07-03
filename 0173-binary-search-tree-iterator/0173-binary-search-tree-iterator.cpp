// Approach
// 1. Stack use kraange taaki inorder traversal iterative tarike naal kar sakiye.
// 2. Constructor ch root ton leftmost node tak saare nodes stack ch push kar devaange.
// 3. next() call hon te stack da top node answer hovega.
// 4. Top node nu pop karan to baad je usda right child hove,
//    ta usde right subtree de saare left nodes stack ch push kar devaange.
// 5. hasNext() sirf check karega ki stack empty hai ya nahi.
// 6. Is tarah har next() call te next smallest element mil jaavega.

class BSTIterator
{
public:
    stack<TreeNode*>st;

    void pushAll(TreeNode* root)
    {
        while(root!=NULL)
        {
            st.push(root);

            root=root->left;
        }
    }

    BSTIterator(TreeNode* root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode* temp=st.top();
        st.pop();

        if(temp->right)
        {
            pushAll(temp->right);
        }

        return temp->val;
    }

    bool hasNext()
    {
        return st.empty()==false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj=new BSTIterator(root);
 * int param_1=obj->next();
 * bool param_2=obj->hasNext();
 */