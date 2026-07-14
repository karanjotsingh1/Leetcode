// Approach
// 1. Pehla sorted linked list nu
//    vector ch convert karaange.
// 2. Hun vector te Binary Search waali approach use karaange.
// 3. Har recursive call ch
//    middle element nu root banaavaange.
// 4. Middle de left wale elements
//    left subtree belong karange.
// 5. Middle de right wale elements
//    right subtree belong karange.
// 6. Left te right parts lai
//    recursively BST construct karaange.
// 7. Base case:
//    Je start > end hove,
//    ta NULL return karaange.
// 8. Recursion complete hon to baad
//    balanced BST da root return karaange.

class Solution
{
public:
    TreeNode* build_tree(vector<int>& arr,int start,int end)
    {
        if(start>end)
        {
            return NULL;
        }

        int mid;

        if((end-start)%2==0)
        {
            mid=start+(end-start)/2;
        }
        else
        {
            mid=start+(end-start)/2+1;
        }

        TreeNode* root=new TreeNode(arr[mid]);

        root->left=build_tree(arr,start,mid-1);

        root->right=build_tree(arr,mid+1,end);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head)
    {
        if(head==NULL)
        {
            return NULL;
        }

        vector<int> arr;

        ListNode* temp=head;

        while(temp!=NULL)
        {
            arr.push_back(temp->val);

            temp=temp->next;
        }

        return build_tree(arr,0,arr.size()-1);
    }
};