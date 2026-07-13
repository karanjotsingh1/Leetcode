class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int idx=0;

        for(int i=0;i<n;i++)
        {
            int ele=nums[i];
            int count=1;
            while(i+1 <n && nums[i+1]==nums[i])
            {
                count+=1;
                i++;
            }
            
            if(count>=2)
            {
                nums[idx++]=nums[i];
                nums[idx++]=nums[i];
            }
            else if(count==1)
            {
                nums[idx++]=nums[i];
            }
        }

        return idx;
    }
};