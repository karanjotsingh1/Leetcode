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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
        {
            return;
        }

        ListNode* temp=head;
        vector<int>arr;
        while(temp)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }

        ListNode* ans=new ListNode(-2);
        
        int i=1;
        int j=arr.size()-1;
        temp=head;
        while(i<j)
        {
            ListNode* new_node1=new ListNode(arr[j]);
            temp->next=new_node1;
            temp=temp->next;
            ListNode* new_node=new ListNode(arr[i]);
            temp->next=new_node;
            temp=temp->next;
            
            i++;
            j--;
        }
        if(i==j)
        {
            ListNode* new_node=new ListNode(arr[i]);
            temp->next=new_node;
        }
        
        return;
    }
};