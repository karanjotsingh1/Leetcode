// Approach
// 1. Aapaa current node nu directly delete nhi kr sakde,
//    kyunki previous node da access nhi ditta hoya.
// 2. Is karke current node ch next node di value copy kr devaange.
// 3. Fer current node da next pointer,
//    next node de agge wale node wal point kra devaange.
// 4. Is naal next node list cho remove ho jaega
//    te current node di value vi update ho jaegi.
// 5. Last ch old next node di memory free kr devaange.

class Solution
{
public:
    void deleteNode(ListNode* node)
    {
        ListNode* next_node=node->next;

        // Copy next node's value
        node->val=next_node->val;

        // Skip the next node
        node->next=next_node->next;

        delete next_node;
    }
};