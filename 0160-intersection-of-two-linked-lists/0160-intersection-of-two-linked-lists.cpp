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
        int count1=0;
        int count2=0;

        ListNode* temp1=headA;
        while(temp1!=NULL)
        {
            count1+=1;
            temp1=temp1->next;
        }
        ListNode* temp2=headB;
        while(temp2!=NULL)
        {
            count2+=1;
            temp2=temp2->next;
        }

        temp1=headA;
        temp2=headB;

        if(count1>count2)
        {
            int diff=count1-count2;
            while(diff)
            {
                temp1=temp1->next;
                diff-=1;
            }
        }
        else if(count1<count2)
        {
            int diff=count2-count1;
            while(diff)
            {
                temp2=temp2->next;
                diff-=1;
            }
        }

        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1==temp2)
            {
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;

    }
};