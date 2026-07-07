class Solution {
public:
    bool complete_traversal(vector<pair<int,int>> adj[], vector<bool>&vis,int root,int &min_dist,int n)
    {
        bool last_node=false;
        queue<int>q;
        int mini=INT_MAX;

        q.push(root);
        vis[root]=true;

        while(q.empty()==false)
        {
            int node=q.front();
            q.pop();
            if(node==n)
                last_node=true;
            for(int i=0;i<adj[node].size();i++)
            {
                int neigh_node=adj[node][i].first;
                int neigh_weight=adj[node][i].second;
                if(vis[neigh_node]==false)
                {
                    vis[neigh_node]=true;
                    q.push(neigh_node);
                }
                mini=min(mini,neigh_weight);
            }
        }
        if(last_node)
        {
            min_dist=mini;
            return true;
        }
        return false;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<pair<int,int>> adj[n+1];
        vector<bool>vis(n+1,false);

        for(int i=0;i<roads.size();i++)
        {
            int node1=roads[i][0];
            int node2=roads[i][1];
            int dis=roads[i][2];

            adj[node1].push_back({node2,dis});
            adj[node2].push_back({node1,dis});
            
        }

        for(int i=1;i<=n;i++)
        {
            if(vis[i]==false)
            {   
                int min_dist=0;
                if(complete_traversal(adj,vis,i,min_dist,n))
                    return min_dist;

            }
        }
        return 0;
    }
};