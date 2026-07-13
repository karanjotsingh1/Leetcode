class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }       

        int f_col=0;
        int l_col=n-1;

        while(f_col<l_col)
        {
            for(int i=0;i<n;i++)
            {
                swap(matrix[i][f_col],matrix[i][l_col]);
            }
            f_col++;
            l_col--;
        }
        return;
    }
};