class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];

        int n=prerequisites.size();
        vector<int>indegree(numCourses,0);
        for(int i=0;i<n;i++)
        {
            int node1=prerequisites[i][0];
            int node2=prerequisites[i][1];

            indegree[node1]+=1;
            adj[node2].push_back(node1);
        }

        queue<int>q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }

        vector<int>ans;
        vector<bool>vis(numCourses,false);
        if(q.size()==0)
            return ans;

        while(q.empty()==false)
        {
            int node=q.front();
            q.pop();

            vis[node]=true;

            ans.push_back(node);

            for(int i=0;i<adj[node].size();i++)
            {
                int neigh=adj[node][i];
                if(vis[neigh]==false)
                {
                    indegree[neigh]--;
                    if(indegree[neigh]==0)
                        q.push(neigh);
                }

            }
        }
        if(ans.size()!=numCourses)
            ans.clear();
        return ans;




    }
};