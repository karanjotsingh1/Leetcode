// Approach
// 1. Har filled cell lai check karaange
//    ki usdi value valid hai ya nahi.
// 2. Pehla current column check karaange.
//    Je same digit dubara mile,
//    ta board invalid hovega.
// 3. Fir current row check karaange.
//    Je same digit dubara mile,
//    ta board invalid hovega.
// 4. Fir current cell da 3×3 sub-grid find karaange.
//    Starting row = (row/3)*3
//    Starting column = (col/3)*3
// 5. Pura 3×3 box traverse karaange.
//    Je same digit dubara mile
//    (current cell nu chhad ke),
//    ta board invalid hovega.
// 6. Je saare filled cells valid hon,
//    ta true return karaange.

class Solution
{
public:
    bool isValid(vector<vector<char>>& board,int row,int col,char ele)
    {
        // Check column
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==ele && i!=row)
            {
                return false;
            }
        }

        // Check row
        for(int j=0;j<9;j++)
        {
            if(board[row][j]==ele && j!=col)
            {
                return false;
            }
        }

        // Starting indices of 3×3 box
        int startRow=(row/3)*3;
        int startCol=(col/3)*3;

        // Check 3×3 box
        for(int i=startRow;i<startRow+3;i++)
        {
            for(int j=startCol;j<startCol+3;j++)
            {
                if(board[i][j]==ele && (i!=row || j!=col))
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(isValid(board,i,j,board[i][j])==false)
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};