class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();

        vector<bool>vis(n,false);
        int count=0;
        queue<int>q;
        q.push(0);
        vis[0]=true;
        
        while(q.empty()==false)
        {
            int node=q.front();
            q.pop();

            count+=1;

            for(int i=0;i<rooms[node].size();i++)
            {
                int neigh=rooms[node][i];
                if(vis[neigh]==false)
                {
                    vis[neigh]=true;
                    q.push(neigh);
                }

            }
        }
        if(count==n)
            return true;
        
        return false;
    }
};