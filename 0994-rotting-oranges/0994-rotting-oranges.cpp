// Approach
// 1. Pehla saare rotten oranges queue ch push kar devaange.
// 2. Saare fresh oranges ik set ch store kar laange.
// 3. BFS level by level chalaange.
// 4. Har level ik minute represent karega.
// 5. Jis fresh orange de naal rotten orange adjacent hove,
//    usnu rotten bana ke queue ch push kar devaange.
// 6. Naal hi usnu set cho remove kar devaange.
// 7. Je kise time te saare fresh oranges rotten ho jaan,
//    ta current minutes return kar devaange.
// 8. Je BFS khatam ho jaave te fresh oranges bach jaan,
//    ta -1 return kar devaange.

class Solution
{
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>>q;
        set<pair<int,int>>s;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    s.insert({i,j});
                }
                else if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }

        if(q.empty())
        {
            if(s.empty())
            {
                return 0;
            }

            return -1;
        }

        int minutes=0;

        while(q.empty()==false)
        {
            int size=q.size();

            if(s.empty())
            {
                return minutes;
            }

            for(int i=1;i<=size;i++)
            {
                int row=q.front().first;
                int col=q.front().second;
                q.pop();

                if(row+1<n&&grid[row+1][col]==1)
                {
                    grid[row+1][col]=2;

                    s.erase({row+1,col});

                    q.push({row+1,col});
                }

                if(row-1>=0&&grid[row-1][col]==1)
                {
                    grid[row-1][col]=2;

                    s.erase({row-1,col});

                    q.push({row-1,col});
                }

                if(col+1<m&&grid[row][col+1]==1)
                {
                    grid[row][col+1]=2;

                    s.erase({row,col+1});

                    q.push({row,col+1});
                }

                if(col-1>=0&&grid[row][col-1]==1)
                {
                    grid[row][col-1]=2;

                    s.erase({row,col-1});

                    q.push({row,col-1});
                }
            }

            minutes++;
        }

        if(s.empty())
        {
            return minutes;
        }

        return -1;
    }
};