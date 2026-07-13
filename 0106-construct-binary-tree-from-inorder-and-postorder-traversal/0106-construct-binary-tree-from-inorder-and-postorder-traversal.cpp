// Approach
// 1. Postorder da last element hamesha current subtree da root hunda hai.
// 2. Ik unordered_map banaavaange,
//    jithe inorder value di index store hove,
//    taaki root di position O(1) ch mil jaave.
// 3. Current root postorder ton banaavaange.
// 4. Postorder index nu har vaar root banaun ton baad decrease karaange.
// 5. Inorder ch root di position find karaange.
// 6. Kyunki postorder nu reverse direction ch traverse kar rahe haan,
//    is karke pehla right subtree banaavaange.
// 7. Fer left subtree recursively construct karaange.
// 8. Base case:
//    Je inorder range invalid ho jaave,
//    ta NULL return karaange.
// 9. Constructed root return karaange.

class Solution
{
public:
    TreeNode* build(vector<int>& inorder,vector<int>& postorder,int inStart,int inEnd,int& postIdx,unordered_map<int,int>& mp)
    {
        if(inStart>inEnd)
        {
            return NULL;
        }

        TreeNode* root=new TreeNode(postorder[postIdx]);

        postIdx--;

        int pos=mp[root->val];

        // Build right subtree first
        root->right=build(inorder,postorder,pos+1,inEnd,postIdx,mp);

        // Build left subtree
        root->left=build(inorder,postorder,inStart,pos-1,postIdx,mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder)
    {
        unordered_map<int,int> mp;

        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }

        int postIdx=postorder.size()-1;

        return build(inorder,postorder,0,inorder.size()-1,postIdx,mp);
    }
};