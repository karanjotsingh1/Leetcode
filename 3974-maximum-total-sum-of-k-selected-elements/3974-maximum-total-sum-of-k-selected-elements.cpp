class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),greater<>());

        long long total_sum=0;
        for(int i=0;i<k;i++)
        {
                long long ele=nums[i];
                if(mul>0)
                {
                    long long ans=mul*ele;
                    mul-=1;
                    total_sum+=ans;
                }
                else
                {
                    total_sum+=ele;
                }
        }
        return total_sum;
    }
};