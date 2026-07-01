class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
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
            reverse(nums.begin(),nums.end());
            return;
        }
        int last_idx=n-1;
        while(last_idx>pivot)
        {
            if(nums[last_idx]>nums[pivot])
            {
                swap(nums[last_idx],nums[pivot]);
                break;
            }
            last_idx--;
        }
        int first=pivot+1;
        int last= n-1;
        while(first<last)
        {
            swap(nums[first],nums[last]);
            first++;
            last--;
        }
    return ;
    }
};