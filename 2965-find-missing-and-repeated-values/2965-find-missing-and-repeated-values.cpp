// Approach
// 1. Pehlaa aapaa ik frequency array bnaavaange size n*n+1.
// 2. Hun poori grid traverse kraange te har element di frequency count kraange.
// 3. Fer 1 to n*n takk loop chalaavaange.
// 4. Je kise number di frequency 2 aa,
//    oh repeated number houga.
// 5. Je kise number di frequency 0 aa,
//    oh missing number houga.
// 6. Last ch repeated te missing number answer vector ch return kr devaange.

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int total=n*n;

        vector<int>freq(total+1,0);

        // Count frequency of every number
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                freq[grid[i][j]]++;
            }
        }

        int repeated=-1;
        int missing=-1;

        // Find repeated and missing numbers
        for(int i=1;i<=total;i++)
        {
            if(freq[i]==2)
            {
                repeated=i;
            }
            else if(freq[i]==0)
            {
                missing=i;
            }
        }

        return {repeated,missing};
    }
};