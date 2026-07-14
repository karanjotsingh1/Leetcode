class Solution
{
public:
    ListNode* head;
    int length;

    Solution(ListNode* head)
    {
        this->head=head;

        length=0;

        ListNode* temp=head;

        while(temp!=NULL)
        {
            length++;

            temp=temp->next;
        }
    }

    int getRandom()
    {
        int randomIndex=rand()%length;

        ListNode* temp=head;

        while(randomIndex--)
        {
            temp=temp->next;
        }

        return temp->val;
    }
};