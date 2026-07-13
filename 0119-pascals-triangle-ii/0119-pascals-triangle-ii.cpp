class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        vector<int> prev;
        prev.push_back(1);
        if(rowIndex==0)
            return prev;
        for(int i=0;i<rowIndex;i++)
        {
            ans.resize(0);
            ans.push_back(1);
            for(int j=1;j<prev.size();j++)
            {
                ans.push_back(prev[j] + prev[j-1]);
            }
            ans.push_back(1);
            prev=ans;
        }
        return ans;
    }
};