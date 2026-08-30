// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;

        int carry=0;
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;

        while(temp1 || temp2 || carry)
        {
            int sum=0;

            if(temp1)
            {
                sum+=temp1->val;
                temp1=temp1->next;
            }
            if(temp2)
            {
                sum+=temp2->val;
                temp2=temp2->next;
            }
            if(carry)
            {
                sum+=carry;
            }

            if(sum>=10)
            {
                carry=1;
                sum=sum%10;
            }
            else
            {
                carry=0;
            }
            ListNode* next_node=new ListNode(sum);
            temp->next=next_node;
            temp=next_node;
        }
        return ans->next;
    }
};



// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* temp1=l1;
//         ListNode* temp2=l2;
//         int carry=0;
//         int sum=0;

//         ListNode* ans=new ListNode(-1);
//         ListNode* temp=ans;

//         while(sum || temp1 || temp2)
//         {
//             if(temp1)
//             {
//                 sum+=temp1->val;
//                 temp1=temp1->next;
//             }
//             if(temp2)
//             {
//                 sum+=temp2->val;
//                 temp2=temp2->next;
//             }
//             if(carry)
//             {
//                 sum+=carry;
//             }

//             if(sum>=10)
//             {
//                 carry=1;
//                 sum=sum%10;
//             }
//             else
//             {
//                 carry=0;
//             }

//             ListNode* new_node=new ListNode(sum);
//             temp->next=new_node;
//         }
//     }
// };


