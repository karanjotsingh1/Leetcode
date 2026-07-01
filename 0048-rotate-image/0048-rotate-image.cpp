// Approach
// 1. Pehlaa aapaa matrix da transpose kraange.
//    Sirf upper triangle traverse kraange taaki ik pair sirf ik vaar hi swap hove.
// 2. Transpose to baad har row nu reverse kraange.
// 3. Row reverse krde hi matrix 90 degree clockwise rotate ho jaegi.
// 4. Saara kaam in-place hovega, kise extra matrix di lod nhi.

class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n=matrix.size();

        // Transpose the matrix
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        // Reverse every row
        for(int i=0;i<n;i++)
        {
            int first_col=0;
            int last_col=n-1;

            while(first_col<last_col)
            {
                swap(matrix[i][first_col],matrix[i][last_col]);
                first_col++;
                last_col--;
            }
        }
    }
};