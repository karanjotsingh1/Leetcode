/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build_tree(vector<int>& arr,int start,int end)
    {
        if(start>end)
            return NULL;

        int mid;
        if((end-start) %2==0)
            mid=start+ (end-start)/2;
        else
            mid=(start+ (end-start)/2)+1;

        TreeNode* root=new TreeNode(arr[mid]);
        root->left=build_tree(arr,start,mid-1);
        root->right=build_tree(arr,mid+1,end);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        if(head->next==NULL)
        {
            TreeNode* root=new TreeNode(head->val);
            return root;
        }

        vector<int>arr;

        ListNode* temp=head;
        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }

        int start=0;
        int end=arr.size()-1;

        return build_tree(arr,start,end);
    }
};