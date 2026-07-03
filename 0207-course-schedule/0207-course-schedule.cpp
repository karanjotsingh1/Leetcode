// Approach
// 1. Har prerequisite pair [a,b] da matlab b -> a edge hovegi.
// 2. Har node di indegree calculate kraange.
// 3. Jinna nodes di indegree 0 hovegi,
//    ohna nu queue ch push kar devaange.
// 4. Queue cho ik ik node bahar kadhaange.
// 5. Current node de saare neighbours di indegree 1 naal ghataange.
// 6. Je kise neighbour di indegree 0 ho jaave,
//    ta usnu queue ch push kar devaange.
// 7. Jinni nodes process hundiyan jaan,
//    ona da count vadhaunde jaavaange.
// 8. Je aakhir ch processed nodes da count numCourses de equal hove,
//    ta saare courses complete ho sakde ne.
// 9. Nahi ta graph ch cycle hai, is karke false return kar devaange.

class Solution
{
public:
    bool canFinish(int numCourses,vector<vector<int>>& prerequisites)
    {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);

        for(auto &edge:prerequisites)
        {
            adj[edge[1]].push_back(edge[0]);

            indegree[edge[0]]++;
        }

        queue<int>q;

        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        int count=0;

        while(q.empty()==false)
        {
            int node=q.front();
            q.pop();

            count++;

            for(auto child:adj[node])
            {
                indegree[child]--;

                if(indegree[child]==0)
                {
                    q.push(child);
                }
            }
        }

        return count==numCourses;
    }
};