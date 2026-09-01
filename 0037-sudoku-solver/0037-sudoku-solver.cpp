// Approach
// 1. Find the first empty cell.
//
// 2. Try numbers from 1 to 9.
//
// 3. Check whether the number is valid
//    in the current row, column and 3x3 box.
//
// 4. If valid, place the number.
//
// 5. Recursively call the same function
//    to solve the remaining board.
//
// 6. If the board gets solved, stop.
//
// 7. If the choice does not lead to a solution,
//    remove the number and try the next number.
//
// 8. This removing of the number is called
//    BACKTRACKING.

class Solution {
public:

    bool valid_placement(vector<vector<char>>& board,int row,int col,char ele)
    {
        // Vertical line check
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==ele)
            {
                return false;
            }
        }

        // Horizontal line check
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==ele)
            {
                return false;
            }
        }

        // 3x3 box check
        for(int i=(row/3)*3;i<((row/3)+1)*3;i++)
        {
            for(int j=(col/3)*3;j<((col/3)+1)*3;j++)
            {
                if(board[i][j]==ele)
                {
                    return false;
                }
            }
        }

        return true;
    }

    void palcement_kro(vector<vector<char>>& board,bool& solved)
    {
        if(solved)
        {
            return;
        }

        // Find an empty cell
        for(int row=0;row<9;row++)
        {
            for(int col=0;col<9;col++)
            {
                if(board[row][col]=='.')
                {
                    // Try 1 to 9
                    for(int num=1;num<=9;num++)
                    {
                        char ele=char(num+'0');

                        if(valid_placement(board,row,col,ele))
                        {
                            // Place number
                            board[row][col]=ele;

                            // Solve remaining board
                            palcement_kro(board,solved);

                            if(solved)
                            {
                                return;
                            }

                            // Backtrack
                            board[row][col]='.';
                        }
                    }

                    // No number worked for this cell
                    return;
                }
            }
        }

        // No empty cell left
        solved=true;
        return;
    }

    void solveSudoku(vector<vector<char>>& board)
    {
        bool solved=false;

        palcement_kro(board,solved);
    }
};