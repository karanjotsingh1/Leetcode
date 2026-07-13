// Approach
// 1. Disjoint Set Union (DSU) / Union Find use karaange.
// 2. Har node nu initially apna parent banaavaange.
// 3. Har edge lai dono nodes da ultimate parent find karaange.
// 4. Je dono nodes da parent same hove,
//    matlab oh pehla hi connected ne,
//    te current edge cycle bana rahi hai.
//    Eh hi redundant connection hovegi.
// 5. Je parents different hon,
//    ta dono sets nu union kar devaange.
// 6. Traversal complete hon to baad
//    redundant edge return karaange.

class Solution
{
public:
    int findParent(vector<int>& parent,int node)
    {
        if(parent[node]==node)
        {
            return node;
        }

        return parent[node]=findParent(parent,parent[node]);
    }

    void unionSet(vector<int>& parent,vector<int>& rank,int u,int v)
    {
        int pu=findParent(parent,u);
        int pv=findParent(parent,v);

        if(pu==pv)
        {
            return;
        }

        if(rank[pu]<rank[pv])
        {
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu])
        {
            parent[pv]=pu;
        }
        else
        {
            parent[pv]=pu;
            rank[pu]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n=edges.size();

        vector<int> parent(n+1);
        vector<int> rank(n+1,0);

        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }

        for(int i=0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];

            if(findParent(parent,u)==findParent(parent,v))
            {
                return {u,v};
            }

            unionSet(parent,rank,u,v);
        }

        return {};
    }
};