class Solution {
public:
    bool colouring(vector<vector<int>>& graph,int n ,vector<int>&colour,vector<bool>&vis,int i)
    {
        queue<int>q;
        q.push(i);
        vis[i]=true;
        colour[i]=0;

        while(q.empty()==false)
        {
            int node=q.front();
            q.pop();

            for(int i=0;i<graph[node].size();i++)
            {
                int neigh=graph[node][i];
                if(vis[neigh]==false)
                {
                    if(colour[node]==0)
                    {
                        colour[neigh]=1;
                        vis[neigh]=true;
                        q.push(neigh);
                    }
                    else if(colour[node]==1)
                    {
                        colour[neigh]=0;
                        vis[neigh]=true;
                        q.push(neigh);
                    }
                }
                else
                {
                    if(colour[neigh]==colour[node])
                        return false;
                }
            }

        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        
        vector<int>colour(n,-1);
        vector<bool>vis(n,false);

        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
            {
                if(colouring (graph,n,colour,vis,i)==false)
                    return false;
            }
        }
        return true;
         
    }
};