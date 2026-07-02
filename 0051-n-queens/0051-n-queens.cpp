// Approach
// 1. Pehlaa aapaa ik board bnaavaange jithe saari positions '.' naal initialize hon.
// 2. Hun recursion row-wise chalegi.
//    Har recursive call ch sirf current row ch queen place krni aa.
// 3. Har column lai check kraange ki queen safely place ho sakdi aa ja nahi.
// 4. Safety check ch:
//    - Same column check kraange.
//    - Upper left diagonal check kraange.
//    - Upper right diagonal check kraange.
//    Kyunki queens hamesha upper rows ch hi placed hundiyan ne.
// 5. Je position valid hove,
//    ta queen place kraange te next row lai recursive call kraange.
// 6. Jadon row==n ho jaave,
//    matlab ik valid board mil gya, onu answer ch store kr devaange.
// 7. Recursive call ton baad queen remove(backtracking) kr devaange
//    taaki next column try kr sakiye.
// 8. Aive hi saare possible valid boards generate ho jaan ge.

class Solution
{
public:
    bool is_valid_placement(vector<string>& board,int n,int row,int col)
    {
        // Check same column
        for(int i=0;i<row;i++)
        {
            if(board[i][col]=='Q')
            {
                return false;
            }
        }

        // Check upper left diagonal
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }

        // Check upper right diagonal
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }

        return true;
    }

    void queen_placement(vector<string>& board,vector<vector<string>>& ans,int n,int row)
    {
        // One valid arrangement found
        if(row==n)
        {
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++)
        {
            if(is_valid_placement(board,n,row,col))
            {
                // Place the queen
                board[row][col]='Q';

                queen_placement(board,ans,n,row+1);

                // Backtrack
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));

        queen_placement(board,ans,n,0);

        return ans;
    }
};