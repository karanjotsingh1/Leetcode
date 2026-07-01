// Approach
// 1. Pehlaa slow te fast pointer use krke linked list da middle labhaange.
// 2. Hun middle to baad wali half nu reverse kr devaange.
// 3. Ik pointer head ton te ik pointer reversed second half ton start kraange.
// 4. Dono lists nu ik ik node compare kraange.
// 5. Je kise vi node di value different hove,
//    ta false return kr devaange.
// 6. Je poori second half successfully compare ho jaave,
//    ta linked list palindrome aa, true return kr devaange.

/**
 * Definition for singly-linked list.
 * struct ListNode
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x,ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;

        // Find the middle of the linked list
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* prev=NULL;

        // Reverse the second half
        while(slow!=NULL)
        {
            ListNode* next_node=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next_node;
        }

        fast=head;

        // Compare first half with reversed second half
        while(fast!=NULL&&prev!=NULL)
        {
            if(fast->val!=prev->val)
            {
                return false;
            }

            fast=fast->next;
            prev=prev->next;
        }

        return true;
    }
};