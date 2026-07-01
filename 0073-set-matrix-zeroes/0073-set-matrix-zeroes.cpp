// Step 1:
// Traverse the entire matrix.

// Step 2:
// Jithe vi 0 mile,
// usdi row number ik set ch store kr devaange.
// usda column number ik hor set ch store kr devaange.

// Step 3:
// Hun dubara poori matrix traverse kraange.

// Step 4:
// Je current row set ch present aa
// ya current column set ch present aa,
// taan us cell nu 0 kr devaange.

// Step 5:
// Finally updated matrix mil jaegi.

class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int m=matrix.size();
        int n=matrix[0].size();

        unordered_set<int>rows;
        unordered_set<int>cols;

        // Store rows and columns containing 0
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        // Set required cells to 0
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(rows.count(i)||cols.count(j))
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
};