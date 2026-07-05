class Solution {
public:
    void all_paths_s_to_d(vector<vector<int>>& graph,vector<int>&vis,vector<int>&path,vector<vector<int>>&all_paths,int source,int &dest)
    {
        if(source==dest)
        {
            path.push_back(source);
            all_paths.push_back(path);
            
            return;
        }

        vis[source]=true;
        path.push_back(source);
        for(int i=0;i<graph[source].size();i++)
        {
            int neigh=graph[source][i];
            if(vis[neigh]==false)
            {
                all_paths_s_to_d(graph,vis,path,all_paths,neigh,dest);
                path.pop_back();
                vis[neigh]=false;
            }
        }

        return;

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        int source=0;
        int dest=n-1;

        vector<int>vis(n,false);
        vector<int>path;
        vector<vector<int>>all_paths;

        all_paths_s_to_d(graph,vis,path,all_paths,source,dest);

        return all_paths;

    }
};