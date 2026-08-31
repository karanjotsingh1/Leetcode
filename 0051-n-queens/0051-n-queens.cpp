class Solution {
public:
    bool valid_placement(vector<string>&board,int &q_row,int &q_col,int &n)
    {
        // top 
        for(int i=q_row-1;i>=0;i--)
        {
            if(board[i][q_col]=='Q')
                return false;
        }

        // top left
        for(int i=q_row-1,j=q_col-1;i>=0 && j>=0 ; i--,j--)
        {
            if(board[i][j]=='Q')
                return false;
        }

        //top right
        for(int i=q_row-1,j=q_col+1;i>=0 && j<n ; i--,j++)
        {
            if(board[i][j]=='Q')
                return false;
        }

        return true;

    }
    void n_queen(int &n,int curr_row,vector<string>&board,vector<vector<string>>&all_boards)
    {
        if(curr_row==n)
        {
            all_boards.push_back(board);
            return;
        }

        for(int i=0;i<n;i++)
        {
            if(valid_placement(board,curr_row,i,n))
            {
                board[curr_row][i]='Q';
                n_queen(n,curr_row+1,board,all_boards);
                board[curr_row][i]='.';
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>all_boards;
        int curr_row=0;

        n_queen(n,curr_row,board,all_boards);
        return all_boards;
    }
};



// // Approach
// // 1. Pehlaa aapaa ik board bnaavaange jithe saari positions '.' naal initialize hon.
// // 2. Hun recursion row-wise chalegi.
// //    Har recursive call ch sirf current row ch queen place krni aa.
// // 3. Har column lai check kraange ki queen safely place ho sakdi aa ja nahi.
// // 4. Safety check ch:
// //    - Same column check kraange.
// //    - Upper left diagonal check kraange.
// //    - Upper right diagonal check kraange.
// //    Kyunki queens hamesha upper rows ch hi placed hundiyan ne.
// // 5. Je position valid hove,
// //    ta queen place kraange te next row lai recursive call kraange.
// // 6. Jadon row==n ho jaave,
// //    matlab ik valid board mil gya, onu answer ch store kr devaange.
// // 7. Recursive call ton baad queen remove(backtracking) kr devaange
// //    taaki next column try kr sakiye.
// // 8. Aive hi saare possible valid boards generate ho jaan ge.

// class Solution
// {
// public:
//     bool is_valid_placement(vector<string>& board,int n,int row,int col)
//     {
//         // Check same column
//         for(int i=0;i<row;i++)
//         {
//             if(board[i][col]=='Q')
//             {
//                 return false;
//             }
//         }

//         // Check upper left diagonal
//         for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
//         {
//             if(board[i][j]=='Q')
//             {
//                 return false;
//             }
//         }

//         // Check upper right diagonal
//         for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++)
//         {
//             if(board[i][j]=='Q')
//             {
//                 return false;
//             }
//         }

//         return true;
//     }

//     void queen_placement(vector<string>& board,vector<vector<string>>& ans,int n,int row)
//     {
//         // One valid arrangement found
//         if(row==n)
//         {
//             ans.push_back(board);
//             return;
//         }

//         for(int col=0;col<n;col++)
//         {
//             if(is_valid_placement(board,n,row,col))
//             {
//                 // Place the queen
//                 board[row][col]='Q';

//                 queen_placement(board,ans,n,row+1);

//                 // Backtrack
//                 board[row][col]='.';
//             }
//         }
//     }

//     vector<vector<string>> solveNQueens(int n)
//     {
//         vector<vector<string>>ans;
//         vector<string>board(n,string(n,'.'));

//         queen_placement(board,ans,n,0);

//         return ans;
//     }
// };