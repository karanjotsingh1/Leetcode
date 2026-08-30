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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL || head->next==NULL)
            return head;
            
        int count=0;
        ListNode* temp=head;

        while(temp)
        {
            count+=1;
            temp=temp->next;
        }

        k=k%count;
        if(k==0)
        {
            return head;
        }
        int steps=count-k-1;

        temp=head;
        while(steps)
        {
            temp=temp->next;
            steps--;
        }

        ListNode* new_head=temp->next;
        temp->next=NULL;

        temp=new_head;
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=head;

        return new_head;
    }
};



// // Approach
// // 1. Pehla linked list di length calculate karaange.
// // 2. Rotation k nu
// //    k % length kar devaange,
// //    kyunki complete rotations da koi effect nahi hunda.
// // 3. Je k == 0 hove,
// //    ta original head return karaange.
// // 4. New head ton ik node pehla wala node find karaange.
// //    Isde lai (length-k-1) nodes agge move karaange.
// // 5. New head nu store karaange.
// // 6. Current node da next NULL kar devaange,
// //    taaki list do parts ch divide ho jaave.
// // 7. New head ton last node tak traverse karaange.
// // 8. Last node nu original head naal connect karaange.
// // 9. New head return karaange.

// class Solution
// {
// public:
//     ListNode* rotateRight(ListNode* head,int k)
//     {
//         if(head==NULL || head->next==NULL)
//         {
//             return head;
//         }

//         int count=0;

//         ListNode* temp=head;

//         // Find length
//         while(temp!=NULL)
//         {
//             count++;
//             temp=temp->next;
//         }

//         k=k%count;

//         if(k==0)
//         {
//             return head;
//         }

//         // Move to node before new head
//         int move_forward=count-k-1;

//         temp=head;

//         while(move_forward--)
//         {
//             temp=temp->next;
//         }

//         ListNode* new_head=temp->next;

//         temp->next=NULL;

//         // Reach last node
//         temp=new_head;

//         while(temp->next!=NULL)
//         {
//             temp=temp->next;
//         }

//         // Connect last node to old head
//         temp->next=head;

//         return new_head;
//     }
// };