class Solution {
public:
    void calculate_subsets(vector<int>& nums,int idx,vector<int> &subset,vector<vector<int>>&all_subsets,int &n)
    {
        if(idx>=n)
        {
            all_subsets.push_back(subset);
            return;
        }

        subset.push_back(nums[idx]);
        calculate_subsets(nums,idx+1,subset,all_subsets,n);
        subset.pop_back();

        calculate_subsets(nums,idx+1,subset,all_subsets,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subset;
        vector<vector<int>>all_subsets;
        
        int n=nums.size();
        
        calculate_subsets(nums,0,subset,all_subsets,n);

        return all_subsets;
    }
};