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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;

        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                ListNode* next_node=new ListNode(list1->val);
                temp->next=next_node;
                temp=next_node;
                list1=list1->next;
            }
            else if(list1->val > list2->val)
            {
                ListNode* next_node=new ListNode(list2->val);
                temp->next=next_node;
                temp=next_node;
                list2=list2->next;
            }
            else
            {
                ListNode* next_node1=new ListNode(list1->val);
                temp->next=next_node1;
                temp=next_node1;
                list1=list1->next;
                ListNode* next_node2=new ListNode(list2->val);
                temp->next=next_node2;
                temp=next_node2;
                list2=list2->next;
            }
        }
        while(list1)
        {
             ListNode* next_node=new ListNode(list1->val);
            temp->next=next_node;
            temp=next_node;
            list1=list1->next;
        }
        while(list2)
        {
            ListNode* next_node=new ListNode(list2->val);
            temp->next=next_node;
            temp=next_node;
            list2=list2->next;
        }
        return ans->next;
    }
};



// // Approach
// // 1. Ik dummy node banaavaange,
// //    jo merged list da starting point hovega.
// // 2. Ik pointer (temp) maintain karaange,
// //    jo merged list da last node represent karega.
// // 3. Dono linked lists nu simultaneously traverse karaange.
// // 4. Je list1 da current node chhota ya equal hove,
// //    ta us node nu merged list ch attach karaange
// //    te list1 nu agge move karaange.
// // 5. Nahi ta list2 da current node attach karaange
// //    te list2 nu agge move karaange.
// // 6. Har attachment ton baad
// //    temp nu agge move karaange.
// // 7. Jadon kise ik list de nodes khatam ho jaan,
// //    ta doosri list de saare remaining nodes
// //    directly merged list ch attach kar devaange.
// // 8. Dummy node de next nu return karaange,
// //    jo merged sorted list da head hovega.

// class Solution
// {
// public:
//     ListNode* mergeTwoLists(ListNode* list1,ListNode* list2)
//     {
//         ListNode* head=new ListNode(-1);

//         ListNode* temp=head;

//         while(list1!=NULL && list2!=NULL)
//         {
//             if(list1->val<=list2->val)
//             {
//                 temp->next=list1;

//                 list1=list1->next;
//             }
//             else
//             {
//                 temp->next=list2;

//                 list2=list2->next;
//             }

//             temp=temp->next;
//         }

//         if(list1!=NULL)
//         {
//             temp->next=list1;
//         }

//         if(list2!=NULL)
//         {
//             temp->next=list2;
//         }

//         return head->next;
//     }
// };