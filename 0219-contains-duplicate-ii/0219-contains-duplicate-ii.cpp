class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        unordered_set<int>s;

        int n=nums.size();
        if(n==1)
            return false;

        for(int i=0;i<n;i++)
        {
            if(s.find(nums[i])!=s.end())
            {
                int diff=i-m[nums[i]];
                if(diff<=k)
                    return true;
            }
            s.insert(nums[i]);
            m[nums[i]]=i;
        }
        return false;
    }
};