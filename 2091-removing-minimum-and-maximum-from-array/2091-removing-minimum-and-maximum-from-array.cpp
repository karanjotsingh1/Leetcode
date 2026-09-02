class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();

        int mini=0;
        int maxi=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]<nums[mini])
            {
                mini=i;
            }

            if(nums[i]>nums[maxi])
            {
                maxi=i;
            }
        }

        int left=min(mini,maxi);
        int right=max(mini,maxi);

        int first=right+1;
        int second=n-left;
        int third=left+1+n-right;

        return min(first,min(second,third));
    }
};