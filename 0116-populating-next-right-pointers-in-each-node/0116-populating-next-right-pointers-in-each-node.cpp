// Approach
// 1. Je root NULL hove ta sidha NULL return kar devaange.
// 2. Ik queue use kraange taaki tree nu level by level traverse kar sakiye (BFS).
// 3. Har level da size store kraange.
// 4. Hun us level de saare nodes ik ik karke queue cho bahar kadhaange.
// 5. Je current node level da last node nahi hai,
//    ta usda next queue de front node naal connect kar devaange.
// 6. Je current node level da last node hai,
//    ta usda next NULL set kar devaange.
// 7. Fir current node de left te right child queue ch push kar devaange.
// 8. Saare levels process hon to baad root return kar devaange.

class Solution
{
public:
    Node* connect(Node* root)
    {
        if(root==NULL)
        {
            return NULL;
        }

        queue<Node*>q;
        q.push(root);

        while(q.empty()==false)
        {
            int n=q.size();

            for(int i=1;i<=n;i++)
            {
                Node* temp=q.front();
                q.pop();

                if(i!=n)
                {
                    temp->next=q.front();
                }
                else
                {
                    temp->next=NULL;
                }

                if(temp->left)
                {
                    q.push(temp->left);
                }

                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
        }

        return root;
    }
};