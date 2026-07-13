// Approach
// 1. Preorder da first element hamesha current subtree da root hunda hai.
// 2. Ik unordered_map banaavaange,
//    jithe inorder value di index store hove,
//    taaki root di position O(1) ch mil jaave.
// 3. Current root preorder ton banaavaange.
// 4. Inorder ch root di position find karaange.
// 5. Root de left wale elements
//    left subtree belong karde ne.
// 6. Root de right wale elements
//    right subtree belong karde ne.
// 7. Preorder index nu har vaar root banaun ton baad increase karaange.
// 8. Recursively pehla left subtree
//    te fer right subtree construct karaange.
// 9. Base case:
//    Je inorder range invalid ho jaave,
//    ta NULL return karaange.

class Solution
{
public:
    TreeNode* build(vector<int>& preorder,vector<int>& inorder,int inStart,int inEnd,int& preIdx,unordered_map<int,int>& mp)
    {
        if(inStart>inEnd)
        {
            return NULL;
        }

        TreeNode* root=new TreeNode(preorder[preIdx]);

        preIdx++;
        int pos=mp[root->val];

        root->left=build(preorder,inorder,inStart,pos-1,preIdx,mp);
        root->right=build(preorder,inorder,pos+1,inEnd,preIdx,mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder)
    {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        int preIdx=0;

        return build(preorder,inorder,0,inorder.size()-1,preIdx,mp);
    }
};