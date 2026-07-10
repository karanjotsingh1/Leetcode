class Solution {
public:
    void combinations(vector<int>& candidates, int target,int &n,vector<int>&combo,vector<vector<int>>&ans,int idx,set<vector<int>>&s)
    {   
        if(idx>=n)
            return;

        if(target<candidates[idx])
            return;

        if(target==candidates[idx])
        {
            combo.push_back(candidates[idx]);
            if(s.find(combo)==s.end())
            {
                ans.push_back(combo);
                s.insert(combo);
            }
            combo.pop_back();
            return;
        }

        combo.push_back(candidates[idx]);
        combinations(candidates,target-candidates[idx],n,combo,ans,idx,s);
        combo.pop_back();

        combinations(candidates,target,n,combo,ans,idx+1,s);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();

        sort(candidates.begin(),candidates.end());

        set<vector<int>>s;

        vector<vector<int>>ans;
        vector<int>combo;

        int idx=0;
        combinations(candidates,target,n,combo,ans,idx,s);

        return ans;
    }
};