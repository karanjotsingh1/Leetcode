// Approach
// 1. Adjacency matrix di har row traverse kraange.
// 2. Har row ch kinne 1's ne,
//    oh count kraange.
// 3. Row da count hi us vertex di degree hovegi.
// 4. Degree nu answer vector ch store kar devaange.
// 5. Aakhir ch answer return kar devaange.

class Solution
{
public:
    vector<int> findDegrees(vector<vector<int>>& matrix)
    {
        int n=matrix.size();

        vector<int>ans(n,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==1)
                {
                    ans[i]++;
                }
            }
        }

        return ans;
    }
};
