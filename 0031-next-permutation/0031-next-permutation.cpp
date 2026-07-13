class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();

        if(n==0)
            return;
        
        int pivot=-1;

        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                pivot=i;
                break;
            }
        }

        if(pivot==-1)
        {
            sort(nums.begin(),nums.end());
            return;
        }

        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>nums[pivot])
            {
                swap(nums[i],nums[pivot]);
                break;
            }
        }

        int left=pivot+1;
        int ryt=n-1;

        while(left<ryt)
        {
            swap(nums[left],nums[ryt]);
            left++;
            ryt--;
        }

        return;
    }
};