class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        set<pair<int,int>>s;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    s.insert({i,j});
                }
            }
        }
        for (auto ele : s)
        {
            int i=ele.first;
            int j=ele.second;

            s.erase(ele);
            for(int j=0;j<m;j++)
            {
            matrix[i][j]=0;
            }
            for(int i=0;i<n;i++)
            {
                matrix[i][j]=0;
            }
        }
        return ;     
    }
};