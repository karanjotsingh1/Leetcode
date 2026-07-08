class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ii=1;
        
        int n=nums.size();
        set<int>s;

        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }

        while(s.find(ii)!=s.end())
        {
            ii++;
        }
    
    return ii;
    }
};