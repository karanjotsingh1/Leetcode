// Approach
// 1. Pehlaa aapaa first row te first column nu marker vangu use kraange.
// 2. Je kise cell ch 0 mile ta usdi row da first element te column da first element 0 kr devaange.
// 3. First column already marker aa, is karke ik variable(col0) rakhange taaki yaad rhe first column nu vi baad ch 0 krna aa ja nahi.
// 4. Hun markers de basis te baaki matrix update kraange.
// 5. Last ch first row te first column nu separately handle kraange.

class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int m=matrix.size();
        int n=matrix[0].size();

        int col0=1;

        // Mark rows and columns
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]==0)
            {
                col0=0;
            }

            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        // Fill matrix using markers
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][0]==0||matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }

        // Handle first row
        if(matrix[0][0]==0)
        {
            for(int j=0;j<n;j++)
            {
                matrix[0][j]=0;
            }
        }

        // Handle first column
        if(col0==0)
        {
            for(int i=0;i<m;i++)
            {
                matrix[i][0]=0;
            }
        }
    }
};