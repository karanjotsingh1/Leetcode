// Approach
// 1. Array already sorted hai, is karke middle element nu root banaange.
// 2. Middle choose karan naal left te right subtree almost equal size de banange,
//    jis naal height minimum rahegi.
// 3. Left half ton recursively left subtree banaange.
// 4. Right half ton recursively right subtree banaange.
// 5. Je first last ton vadda ho jaave,
//    ta matlab koi element nahi bacheya, NULL return kar devaange.
// 6. Har recursive call ik balanced BST da ik hissa banaaundi hai.
// 7. Aakhir ch poori height-balanced BST return ho jaavegi.

class Solution
{
public:
    TreeNode* make_bst(vector<int>& nums,int first,int last)
    {
        if(first>last)
        {
            return NULL;
        }

        int mid=first+(last-first)/2;

        TreeNode* node=new TreeNode(nums[mid]);

        node->left=make_bst(nums,first,mid-1);

        node->right=make_bst(nums,mid+1,last);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return make_bst(nums,0,nums.size()-1);
    }
};