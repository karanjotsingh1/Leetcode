// Approach
// 1. Pehlaa aapaa ik 2D vector(result) bnaava ge jo saari triangle store kru ga.
// 2. Hun har row ik ik krke bnaava ge.
// 3. Har row da size row number+1 houga te saare elements nu pehlaa 1 naal initialize kr deva ge.
// 4. Hun first te last element ta hamesha 1 rehnde ne, is karke sirf middle elements calculate krne aa.
// 5. Middle value upper row de do adjacent elements da sum houga.
// 6. Har completed row nu result vich store krde jaava ge.
// 7. Last ch poori Pascal's Triangle return kr deva ge.

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>>result;

        for(int i=0;i<numRows;i++)
        {
            vector<int>row(i+1,1);

            // Fill only the middle elements
            for(int j=1;j<i;j++)
            {
                row[j]=result[i-1][j-1]+result[i-1][j];
            }

            result.push_back(row);
        }

        return result;
    }
};