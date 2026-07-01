class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1)
            return n;

        int count=1;
        int idx=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
            {
                continue;
            }
            else
            {
                nums[idx]=nums[i];
                idx++;
                count++;
            }
        }
        return count;
    }
};