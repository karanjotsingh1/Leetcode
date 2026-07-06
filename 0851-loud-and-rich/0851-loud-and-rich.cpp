// Approach
// 1. Richer relations ton directed graph banaange.
//    Edge u->v da matlab u v ton richer hai.
// 2. Har node di indegree calculate kraange.
// 3. Har person lai initially answer oh khud hovega.
// 4. Jinna nodes di indegree 0 hove,
//    ohna nu queue ch push kar devaange.
// 5. Kahn's Topological Sort perform kraange.
// 6. Current node de saare neighbours check kraange.
// 7. Je current node da quietest person,
//    neighbour de quietest person ton zyada quiet hove,
//    ta neighbour da answer update kar devaange.
// 8. Neighbour di indegree decrease kraange.
// 9. Je indegree 0 ho jaave,
//    ta neighbour nu queue ch push kar devaange.
// 10. Topological traversal complete hon to baad,
//     answer vector return kar devaange.

class Solution
{
public:
    vector<int> loudAndRich(vector<vector<int>>& richer,vector<int>& quiet)
    {
        int n=quiet.size();

        vector<int>adj[n];
        vector<int>indegree(n,0);

        for(int i=0;i<richer.size();i++)
        {
            int u=richer[i][0];
            int v=richer[i][1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<int>ans(n);

        for(int i=0;i<n;i++)
        {
            ans[i]=i;
        }

        queue<int>q;

        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        while(q.empty()==false)
        {
            int node=q.front();
            q.pop();

            for(int i=0;i<adj[node].size();i++)
            {
                int neigh=adj[node][i];

                if(quiet[ans[node]]<quiet[ans[neigh]])
                {
                    ans[neigh]=ans[node];
                }

                indegree[neigh]--;

                if(indegree[neigh]==0)
                {
                    q.push(neigh);
                }
            }
        }

        return ans;
    }
};