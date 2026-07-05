// Approach
// 1. Har prerequisite pair [a,b] da matlab b -> a edge hovegi.
// 2. Har node di indegree calculate kraange.
// 3. Jinna nodes di indegree 0 hovegi,
//    ohna nu queue ch push kar devaange.
// 4. Queue cho ik ik node bahar kadhaange.
// 5. Current node nu answer ch add kraange.
// 6. Current node de saare neighbours di indegree 1 naal ghataange.
// 7. Je kise neighbour di indegree 0 ho jaave,
//    ta usnu queue ch push kar devaange.
// 8. Je answer ch numCourses nodes aa jaan,
//    ta ohi topological order hovega.
// 9. Nahi ta cycle exist kardi hai,
//    is karke empty vector return kar devaange.

class Solution
{
public:
    vector<int> findOrder(int numCourses,vector<vector<int>>& prerequisites)
    {
        vector<int>adj[numCourses];

        vector<int>indegree(numCourses,0);

        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];

            adj[u].push_back(v);

            indegree[v]++;
        }

        queue<int>q;

        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        vector<int>ans;

        while(q.empty()==false)
        {
            int node=q.front();
            q.pop();

            ans.push_back(node);

            for(int i=0;i<adj[node].size();i++)
            {
                int neigh=adj[node][i];

                indegree[neigh]--;

                if(indegree[neigh]==0)
                {
                    q.push(neigh);
                }
            }
        }

        if(ans.size()!=numCourses)
        {
            return {};
        }

        return ans;
    }
};