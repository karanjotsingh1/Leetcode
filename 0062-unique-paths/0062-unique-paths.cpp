// 1. Grid has m rows and n columns.
//    We start from the top-left cell (0,0)
//    and have to reach the bottom-right cell.

// 2. At every cell, we can move only:
//       → Right
//       ↓ Down

// 3. Create a 2D DP array:
   
//    dp[i][j] = number of unique ways
//               to reach cell (i,j)
//               from cell (0,0).

// 4. For the first row:
//    We can only move RIGHT.
//    Therefore, there is only 1 way
//    to reach every cell.

// 5. For the first column:
//    We can only move DOWN.
//    Therefore, there is only 1 way
//    to reach every cell.

// 6. For every other cell (i,j):
   
//    We can reach it from:
   
//       UP    → dp[i-1][j]
//       LEFT  → dp[i][j-1]

//    Therefore:

//       dp[i][j] =
//       dp[i-1][j] + dp[i][j-1]

// 7. Fill the complete DP table
//    from top-left to bottom-right.

// 8. The bottom-right cell
//    dp[m-1][n-1] contains the
//    total number of unique paths.

// 9. Return dp[m-1][n-1].

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m,vector<int>(n,0));

        // First row
        for(int j=0;j<n;j++)
        {
            dp[0][j]=1;
        }

        // First column
        for(int i=0;i<m;i++)
        {
            dp[i][0]=1;
        }

        // Fill remaining cells
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};