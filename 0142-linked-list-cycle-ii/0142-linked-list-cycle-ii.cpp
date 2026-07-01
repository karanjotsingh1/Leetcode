// Approach
// 1. Pehlaa slow te fast pointer use krke check kraange ki cycle exist krdi aa ja nahi.
// 2. Slow ik step te fast do steps chalega.
// 3. Je dono pointers mil jaan,
//    matlab cycle present aa.
// 4. Je fast ya fast->next NULL ho jaave,
//    matlab cycle nhi aa, NULL return kr devaange.
// 5. Hun fast nu dubara head te le aavaange,
//    te slow nu meeting point te hi rehna devaange.
// 6. Hun dove pointers ik ik step move kraange.
// 7. Jithe dove dubara milange,
//    ohi cycle da starting node houga.
// 8. Ohi node return kr devaange.

/**
 * Definition for singly-linked list.
 * struct ListNode
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    ListNode* detectCycle(ListNode* head)
    {
        if(head==NULL||head->next==NULL)
        {
            return NULL;
        }

        ListNode* slow=head;
        ListNode* fast=head;

        // Detect whether a cycle exists
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast)
            {
                break;
            }
        }

        // No cycle found
        if(fast==NULL||fast->next==NULL)
        {
            return NULL;
        }

        fast=head;

        // Find the starting node of the cycle
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }

        return slow;
    }
};