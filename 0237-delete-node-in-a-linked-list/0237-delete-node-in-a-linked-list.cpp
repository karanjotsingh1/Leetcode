// Approach
// 1. Current node nu directly delete nhi kar sakde,
//    kyunki previous node da access available nahi hai.
// 2. Is karke next node di value current node ch copy karaange.
// 3. Current node da next pointer nu
//    next node de agge wale node wal point karaange.
// 4. Is naal next node effectively list cho remove ho jaega.
// 5. Last ch old next node di memory free kar devaange.

class Solution
{
public:
    void deleteNode(ListNode* node)
    {
        ListNode* next_node=node->next;

        node->val=next_node->val;

        node->next=next_node->next;

        delete next_node;
    }
};