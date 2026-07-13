class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];

        int x_o_r=nums[0];
        for(int i=1;i<n;i++)
        {
            x_o_r=x_o_r ^ nums[i];
        }
        return x_o_r;
    }
};