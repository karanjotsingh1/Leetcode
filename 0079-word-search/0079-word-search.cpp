 // Approach
// 1. Board de har cell ton word start karan di koshish karaange.
// 2. DFS + Backtracking use karaange.
// 3. Je current cell board di boundary ton bahar hove,
//    ya already visited hove,
//    ya current character match na kare,
//    ta false return karaange.
// 4. Je word da last character match ho jaave,
//    ta true return karaange.
// 5. Current cell nu visited mark karaange.
// 6. Fir 4 directions (Up, Down, Left, Right)
//    ch recursively search karaange.
// 7. Je kise vi direction ch word mil jaave,
//    ta true return karaange.
// 8. Je word na mile,
//    ta current cell nu unvisited mark karke
//    backtrack karaange.
// 9. Saare starting cells check karan to baad
//    je word na mile,
//    ta false return karaange.

class Solution
{
public:
    bool dfs(vector<vector<char>>& board,string& word,int row,int col,int idx,vector<vector<bool>>& visited)
    {
        if(idx==word.size())
        {
            return true;
        }

        if(row<0||row>=board.size()||col<0||col>=board[0].size())
        {
            return false;
        }

        if(visited[row][col]==true)
        {
            return false;
        }

        if(board[row][col]!=word[idx])
        {
            return false;
        }

        visited[row][col]=true;

        bool found=
            dfs(board,word,row+1,col,idx+1,visited)||
            dfs(board,word,row-1,col,idx+1,visited)||
            dfs(board,word,row,col+1,idx+1,visited)||
            dfs(board,word,row,col-1,idx+1,visited);

        visited[row][col]=false;

        return found;
    }

    bool exist(vector<vector<char>>& board,string word)
    {
        int n=board.size();
        int m=board[0].size();

        vector<vector<bool>>visited(n,vector<bool>(m,false));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dfs(board,word,i,j,0,visited))
                {
                    return true;
                }
            }
        }

        return false;
    }
};