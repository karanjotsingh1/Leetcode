/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len_a=0;
        int len_b=0;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1)
        {
            len_a+=1;
            temp1=temp1->next;
        }
        while(temp2)
        {
            len_b+=1;
            temp2=temp2->next;
        }
        temp1=headA;
        temp2=headB;

        int diff=abs(len_a-len_b);
        if(len_a>len_b)
        {
            while(diff)
            {
                temp1=temp1->next;
                diff--;
            }
        }
        else if(len_a<len_b)
        {
            while(diff)
            {
                temp2=temp2->next;
                diff--;
            }
        }
        while(temp1 && temp2)
        {
            if(temp1 == temp2)
            {
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};