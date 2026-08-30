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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true;

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* prev=NULL;
        while(slow)
        {
            ListNode* next_node=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next_node;
        }

        fast=head;
        while(fast && prev)
        {
            if(fast->val!=prev->val)
                return false;

            fast=fast->next;
            prev=prev->next;
        }
        return true;
    }
};













// // Approach
// // 1. Slow te Fast pointers use karke
// //    linked list da middle node find karaange.
// // 2. Slow ik step move karega,
// //    jadki Fast do steps move karega.
// // 3. Jadon Fast end te pahunch jaave,
// //    Slow middle node te hovega.
// // 4. Middle ton agge wali linked list
// //    reverse karaange.
// // 5. Ik pointer head ton
// //    te ik pointer reversed second half ton
// //    start karaange.
// // 6. Dono halves de corresponding nodes compare karaange.
// // 7. Je kise vi position te values different hon,
// //    ta linked list palindrome nahi hai.
// //    False return karaange.
// // 8. Je saare nodes match kar jaan,
// //    ta linked list palindrome hai.
// //    True return karaange.

// class Solution
// {
// public:
//     bool isPalindrome(ListNode* head)
//     {
//         if(head==NULL || head->next==NULL)
//         {
//             return true;
//         }

//         // Find middle
//         ListNode* slow=head;
//         ListNode* fast=head;

//         while(fast!=NULL && fast->next!=NULL)
//         {
//             slow=slow->next;
//             fast=fast->next->next;
//         }

//         // Reverse second half
//         ListNode* prev=NULL;

//         while(slow!=NULL)
//         {
//             ListNode* next_node=slow->next;

//             slow->next=prev;

//             prev=slow;

//             slow=next_node;
//         }

//         // Compare both halves
//         fast=head;

//         while(fast!=NULL && prev!=NULL)
//         {
//             if(fast->val!=prev->val)
//             {
//                 return false;
//             }

//             fast=fast->next;
//             prev=prev->next;
//         }

//         return true;
//     }
// };