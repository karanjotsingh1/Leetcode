class Solution {
public:
    void subset_combination(vector<int>& nums,int& n, int idx,vector<int>&subset,vector<vector<int>>& subsets)
    {
        if(idx>n)
            return;
        if(idx==n)
        {
            subsets.push_back(subset);
            return;
        }

        subset.push_back(nums[idx]);
        subset_combination(nums,n,idx+1,subset,subsets);
        subset.pop_back();

        subset_combination(nums,n,idx+1,subset,subsets);

        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();

        vector<int>subset;
        vector<vector<int>>subsets;
        int idx=0;

        subset_combination(nums,n,idx,subset,subsets);

        return subsets;
    }
};