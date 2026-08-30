
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


    
    /*
    // Approach
    // 1. Pehla original linked list nu traverse karaange.
    // 2. Har original node da ik new copied node banaange.
    // 3. Hash map ch store karaange:
    //
    //    original node -> copied node
    //
    // 4. Second traversal karaange.
    // 5. Har copied node da next pointer set karaange
    //    using the map.
    // 6. Har copied node da random pointer vi set karaange
    //    using the map.
    // 7. Finally copied head return karaange.
    */
    
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL)
            return NULL;

        unordered_map<Node*,Node*> m;
        Node* temp=head;

        // First traversal:
        // Create all copied nodes
        while(temp!=NULL)
        {
            Node* new_node=new Node(temp->val);
            m[temp]=new_node;
            temp=temp->next;
        }

        // Second traversal:
        // Connect next and random pointers
        temp=head;
        while(temp!=NULL)
        {
            m[temp]->next=m[temp->next];
            m[temp]->random=m[temp->random];
            temp=temp->next;
        }

        return m[head];
    }
};