class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];

        int majority_ele=0;
        int freq=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i] == nums[majority_ele])
            {
                freq++;
            }
            else
            {
                freq--;
                if(freq<0)
                {
                    freq=0;
                    majority_ele=i;
                }
            }
        }
        return nums[majority_ele];
    }
};