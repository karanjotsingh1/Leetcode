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
    int getDecimalValue(ListNode* head) {
        int ans=0;

        int count=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            count+=1;
            temp=temp->next;
        }
        count-=1;
        temp=head;
        while(temp!=NULL)
        {
            if(temp->val==1)
            {
                ans+=pow(2,count);
            }
            count--;
            temp=temp->next;
        }

        return ans;
    }
};