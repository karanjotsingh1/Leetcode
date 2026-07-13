class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();

        int left=0;
        int ryt=n-1;

        vector<int>ans;
        int first=-1;
        int last=-1;

        while(left<=ryt)
        {
            int mid=left+ ((ryt-left)/2);

            if(target > nums[mid])
            {
                left=mid+1;
            }
            else if(target < nums[mid])
            {
                ryt=mid-1;
            }
            else
            {
                first=mid;
                ryt=mid-1;
            }
        }

        left=0;
        ryt=n-1;
        
        while(left<=ryt)
        {
            int mid=left+ ((ryt-left)/2);

            if(target > nums[mid])
            {
                left=mid+1;
            }
            else if(target < nums[mid])
            {
                ryt=mid-1;
            }
            else
            {
                last=mid;
                left=mid+1;
            }
        }

        return {first,last};
    }
};