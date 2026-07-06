// Approach
// 1. Flight list ton adjacency list banaange.
// 2. Queue ch (stops,node,cost) store kraange.
// 3. Distance array maintain kraange,
//    jithe har node tak hun tak di minimum cost store hovegi.
// 4. Source node ton BFS start kraange.
// 5. Jadon tak queue empty na hove,
//    front state nu bahar kadhaange.
// 6. Je current stops k ton vadh ho jaan,
//    ta us path nu ignore kar devaange.
// 7. Current node de saare neighbours check kraange.
// 8. Je neighbour tak current path di cost
//    pehla stored cost ton ghatt hove,
//    ta distance update karke
//    neighbour nu queue ch push kar devaange.
// 9. BFS complete hon to baad,
//    je destination di distance update na hove,
//    ta -1 return kraange.
// 10. Nahi ta destination di minimum cost return kraange.

class Solution
{
public:
    int findCheapestPrice(int n,vector<vector<int>>& flights,int src,int dst,int k)
    {
        vector<pair<int,int>>adj[n];

        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];

            adj[u].push_back({v,wt});
        }

        vector<int>dist(n,INT_MAX);

        queue<pair<pair<int,int>,int>>q;
        // {{stops,node},cost}

        q.push({{0,src},0});
        dist[src]=0;

        while(q.empty()==false)
        {
            int stops=q.front().first.first;
            int node=q.front().first.second;
            int cost=q.front().second;
            q.pop();

            if(stops>k)
            {
                continue;
            }

            for(int i=0;i<adj[node].size();i++)
            {
                int neigh=adj[node][i].first;
                int wt=adj[node][i].second;

                if(cost+wt<dist[neigh])
                {
                    dist[neigh]=cost+wt;
                    q.push({{stops+1,neigh},cost+wt});
                }
            }
        }

        if(dist[dst]==INT_MAX)
        {
            return -1;
        }

        return dist[dst];
    }
};