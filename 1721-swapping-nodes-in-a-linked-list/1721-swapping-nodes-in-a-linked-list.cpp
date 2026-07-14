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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int>arr;

        if(head==NULL)
            return NULL;

        ListNode* temp=head;
        while(temp)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }

        temp=head;
        int i=0;

        swap(arr[k-1],arr[arr.size()-k]);
        
        while(temp)
        {
            temp->val=arr[i++];
            temp=temp->next;

        }
        return head;
    }
};