class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans(2);
        int n=grid.size();

        int sum_of_n2_numbers=(n*n)*((n*n) +1)/2;
        int sum=0;

        set<int>s;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(s.find(grid[i][j])==s.end())
                {
                    sum+=grid[i][j];
                    s.insert(grid[i][j]);
                }
                else
                {
                    ans[0]=grid[i][j];
                }
            }
        }
        ans[1]=sum_of_n2_numbers-sum;
        return ans;
    }
};