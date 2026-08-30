class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    break;
                }
                else
                {
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }

        int left_col=0;
        int ryt_col=n-1;

        while(left_col<ryt_col)
        {
            for(int i=0;i<n;i++)
            {
                swap(matrix[i][left_col],matrix[i][ryt_col]);
            }
            left_col++;
            ryt_col--;
        }
        return;
    }
    
};

// // Approach
// // 1. Pehla matrix da transpose karaange.
// //    Matlab matrix[i][j] nu matrix[j][i] naal swap karaange.
// // 2. Transpose karan to baad
// //    har row de first column nu
// //    last column naal swap karaange.
// // 3. Fer second column nu
// //    second last column naal swap karaange.
// // 4. Is tarah har row reverse ho jaavegi.
// // 5. Transpose + Reverse rows
// //    milke matrix nu 90° clockwise rotate kar dinde ne.
// // 6. Rotated matrix automatically update ho jaavegi.

// class Solution
// {
// public:
//     void rotate(vector<vector<int>>& matrix)
//     {
//         int n=matrix.size();

//         // Transpose the matrix
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 swap(matrix[i][j],matrix[j][i]);
//             }
//         }

//         // Reverse every row
//         int f_col=0;
//         int l_col=n-1;

//         while(f_col<l_col)
//         {
//             for(int i=0;i<n;i++)
//             {
//                 swap(matrix[i][f_col],matrix[i][l_col]);
//             }

//             f_col++;
//             l_col--;
//         }
//     }
// };