class Solution {
public: 
    void combination(vector<int>& candidates, int target, int idx , vector<vector<int>>&ans, vector<int>&ele)
    {
        if(target==0)
        {
            ans.push_back(ele);
            return;
        }
        
        for(int i=idx;i<candidates.size();i++)
        {
            if(i>idx && candidates[i]==candidates[i-1])
                continue;

            if(candidates[i]>target)
                break;

            ele.push_back(candidates[i]);
            combination(candidates,target-candidates[i],i+1,ans,ele);
            ele.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>ele;
        vector<vector<int>>ans;
        int idx=0;
        sort(candidates.begin(),candidates.end());

        combination(candidates, target, idx, ans, ele);

        return ans;
    }
};