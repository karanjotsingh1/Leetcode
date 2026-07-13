// Approach
// 1. Board de har cell ton search start karaange.
// 2. Je current cell word de first character de equal hove,
//    ta DFS + Backtracking start karaange.
// 3. Har recursive call ch check karaange
//    ki current character word[idx] de equal hai ya nahi.
// 4. Je current cell invalid hove,
//    ya already visited hove,
//    ya character match na kare,
//    ta false return karaange.
// 5. Je idx word di last position te pahunch jaave,
//    matlab poora word mil gaya,
//    ta true return karaange.
// 6. Current cell nu visited mark karaange.
// 7. Four directions (Up, Down, Left, Right)
//    ch recursively search karaange.
// 8. Search complete hon to baad
//    current cell nu unvisited kar devaange
//    (Backtracking),
//    taaki hor paths vi us cell nu use kar sakkan.
// 9. Je kise vi starting cell ton word mil jaave,
//    ta true return karaange,
//    nahi ta false.

class Solution
{
public:
    bool dfs(vector<vector<char>>& board,string& word,int row,int col,int idx,vector<vector<bool>>& vis)
    {
        int n=board.size();
        int m=board[0].size();

        if(row<0 || row>=n || col<0 || col>=m)
        {
            return false;
        }

        if(vis[row][col])
        {
            return false;
        }

        if(board[row][col]!=word[idx])
        {
            return false;
        }

        if(idx==word.size()-1)
        {
            return true;
        }

        vis[row][col]=true;

        bool found=
            dfs(board,word,row+1,col,idx+1,vis) ||
            dfs(board,word,row-1,col,idx+1,vis) ||
            dfs(board,word,row,col+1,idx+1,vis) ||
            dfs(board,word,row,col-1,idx+1,vis);

        vis[row][col]=false;

        return found;
    }

    bool exist(vector<vector<char>>& board,string word)
    {
        int n=board.size();
        int m=board[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(dfs(board,word,i,j,0,vis))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};