// Approach
// 1. Graph disconnected vi ho sakda hai,
//    is karke har unvisited node ton BFS start kraange.
// 2. Har node nu do colours (0 te 1) chon ik colour assign kraange.
// 3. Starting node nu colour 0 assign kar devaange.
// 4. Current node de saare neighbours nu opposite colour assign kraange.
// 5. Je neighbour pehla coloured na hove,
//    ta usnu opposite colour deke queue ch push kar devaange.
// 6. Je neighbour pehla hi current node de same colour da hove,
//    ta graph bipartite nahi hai.
// 7. Je poora graph bina conflict de colour ho jaave,
//    ta graph bipartite hai.

class Solution
{
public:
    bool colouring(vector<vector<int>>& graph,vector<int>& colour,int start)
    {
        queue<int>q;

        q.push(start);
        colour[start]=0;

        while(q.empty()==false)
        {
            int node=q.front();
            q.pop();

            for(int i=0;i<graph[node].size();i++)
            {
                int neigh=graph[node][i];

                if(colour[neigh]==-1)
                {
                    colour[neigh]=1-colour[node];
                    q.push(neigh);
                }
                else if(colour[neigh]==colour[node])
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph)
    {
        int n=graph.size();

        vector<int>colour(n,-1);

        for(int i=0;i<n;i++)
        {
            if(colour[i]==-1)
            {
                if(colouring(graph,colour,i)==false)
                {
                    return false;
                }
            }
        }

        return true;
    }
};