class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();

        vector<vector<int>> dp (m,vector<int>(n,0));

        set<int>s;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(needle[i]==haystack[j])
                {
                    dp[i][j]=1;
                    if(i==0)
                        s.insert(j);
                }
            }
        }
        for (auto ele:s)
        {
            int row=1;
            int col=ele+1;
            while(col<n && row<m && dp[row][col]==1)
            {
                col++;
                row++;
            }
            if(row==m)
                return ele;
        }
        return -1;
    }
};