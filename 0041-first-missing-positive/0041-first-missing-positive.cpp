class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ii=1;
        
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int idx=0;
        while(idx<n && nums[idx]<=0)
            idx++;
        
        for(int i=idx;i<n;i++)
        {
            if(nums[i]!=ii)
                return ii;

            while(i+1<n && nums[i+1]==ii)
                i++;

            ii++;
        }
    return ii;
    }
};