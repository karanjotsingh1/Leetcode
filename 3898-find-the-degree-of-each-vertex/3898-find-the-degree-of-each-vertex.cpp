class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int>count;
        int n = matrix.size();

        vector<int>ans(n,0);

            for(int i=0;i<n;i++)
            {
                int count=0;
                for(int j=0;j<n;j++)
                {
                    if(matrix[i][j] == 1)
                        count+=1;
                }
                ans[i]=count;

            }
        
        return ans;
    }
};