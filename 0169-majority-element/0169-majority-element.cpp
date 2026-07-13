class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();

        if(n==1)
            return nums[0];

        int majority=nums[0];
        int freq=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==majority)
            {
                freq++;
            }
            else
            {
                freq--;
                if(freq==0)
                {
                    majority=nums[i];
                    freq=1;
                }
            }
        }
        return majority;
    }
};