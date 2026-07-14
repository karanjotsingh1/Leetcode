// Approach
// 1. Current level nu traverse karaange.
// 2. Je current node da child na hove,
//    ta simply next node wal move karaange.
// 3. Je child exist kare,
//    ta child list nu recursively flatten karaange.
// 4. Current node da next temporarily store karaange.
// 5. Child list nu current node de next naal connect karaange,
//    te child da prev current node bana devaange.
// 6. Child pointer nu NULL kar devaange,
//    kyunki list flatten ho chukki hovegi.
// 7. Flattened child list de tail nu
//    original next node naal connect karaange.
// 8. Traversal complete hon to baad
//    last node (tail) return karaange.

class Solution
{
public:

    Node* flattenDFS(Node* head)
    {
        Node* current=head;
        Node* last=head;

        while(current!=NULL)
        {
            Node* nextNode=current->next;

            if(current->child!=NULL)
            {
                Node* childHead=current->child;

                Node* childTail=flattenDFS(childHead);

                current->next=childHead;
                childHead->prev=current;

                current->child=NULL;

                if(nextNode!=NULL)
                {
                    childTail->next=nextNode;
                    nextNode->prev=childTail;
                }

                last=childTail;

                current=childTail;
            }
            else
            {
                last=current;
            }

            current=current->next;
        }

        return last;
    }

    Node* flatten(Node* head)
    {
        if(head==NULL)
        {
            return NULL;
        }

        flattenDFS(head);

        return head;
    }
};