class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        for(int i=0;i<dislikes.size();i++)
        {
            int node1=dislikes[i][0];
            int node2=dislikes[i][1];

            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }

        vector<int>colour(n+1);  // two colours (0,1);
        vector<bool>vis(n+1,false);

        queue<int>q;
        vis[0]=true;

        for(int i=1;i<=n;i++)
        {
            if(vis[i]==false)
            {
                q.push(i);
                vis[i]=true;
                colour[i]=0;

                while(q.empty()==false)
                {
                    int node=q.front();
                    q.pop();

                    for(int i=0;i<adj[node].size();i++)
                    {
                        int neigh=adj[node][i];
                        if(vis[neigh]==false)
                        {
                            vis[neigh]=true;
                            q.push(neigh);
                            if(colour[node]==0)
                                colour[neigh]=1;
                            else
                                colour[neigh]=0;
                        }
                        else
                        {
                            if(colour[neigh]==colour[node])
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};