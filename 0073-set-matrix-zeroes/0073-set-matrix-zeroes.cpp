// Approach
// 1. Pehle check karaange
//    ki first row ya first column ch pehla ton koi 0 hai ya nahi.
// 2. Matrix traverse karaange (first row te first column nu chhad ke).
// 3. Je kise cell ch 0 mile,
//    ta usdi row da first element
//    te column da first element 0 mark kar devaange.
// 4. Fer dubara matrix traverse karaange
//    (first row te first column nu chhad ke).
// 5. Je current row da first element
//    ya current column da first element 0 hove,
//    ta current cell nu 0 kar devaange.
// 6. Je first row initially 0 contain kardi si,
//    ta poori first row nu 0 kar devaange.
// 7. Je first column initially 0 contain karda si,
//    ta poora first column nu 0 kar devaange.
// 8. Final modified matrix hi answer hovegi.

class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int n=matrix.size();
        int m=matrix[0].size();

        bool firstRowZero=false;
        bool firstColZero=false;

        // Check first row
        for(int j=0;j<m;j++)
        {
            if(matrix[0][j]==0)
            {
                firstRowZero=true;
                break;
            }
        }

        // Check first column
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]==0)
            {
                firstColZero=true;
                break;
            }
        }

        // Mark rows and columns
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        // Set zeroes using markers
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }

        // Zero first row
        if(firstRowZero)
        {
            for(int j=0;j<m;j++)
            {
                matrix[0][j]=0;
            }
        }

        // Zero first column
        if(firstColZero)
        {
            for(int i=0;i<n;i++)
            {
                matrix[i][0]=0;
            }
        }
    }
};