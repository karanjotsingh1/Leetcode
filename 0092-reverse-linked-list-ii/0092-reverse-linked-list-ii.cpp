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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL || left==right)
            return head;

        

        if(left==1)
        {
            int right1=right;
            ListNode* temp=head;
            ListNode* temp1=head;
            while(right--)
            {
                temp1=temp1->next;
            }
            ListNode* prev=temp1;
            while(right1--)
            {
                ListNode* next_node=temp->next;
                temp->next=prev;
                prev=temp;
                temp=next_node;
            }

            return prev;
        }
        else
        {
            int left1=left;
            int right1=right;

            left=left-2;
            ListNode* first_part_last_node=head;

            while(left--)
            {
                first_part_last_node=first_part_last_node->next;
            }

            ListNode* last_part_first_node=head;
            while(right>0)
            {
                last_part_first_node=last_part_first_node->next;
                right--;
            }

            ListNode* prev=last_part_first_node;
            ListNode* middle_first=first_part_last_node->next;
            int loop=right1-left1+1;
            while(loop--)
            {
                ListNode* next_node=middle_first->next;
                middle_first->next=prev;
                prev=middle_first;
                middle_first=next_node;

            }

            first_part_last_node->next=prev;

            return head;
            


        }

        
    }
};