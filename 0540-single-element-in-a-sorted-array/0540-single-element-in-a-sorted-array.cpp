class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        int first=0;
        int last=n-1;
        int mid=0;

        while(first<last)
        {
            mid=first+((last-first)/2);

            if((mid-1>=0 && nums[mid]!=nums[mid-1]) && (mid+1<n && nums[mid]!=nums[mid+1]))
                return nums[mid];
            
            else if(mid+1<n && nums[mid]==nums[mid+1])
            {
                if((last-mid)%2==1)
                    last=mid-1;
                else
                    first=mid;
            }
            else if((mid-1>=0 && nums[mid]==nums[mid-1]))
            {
                if((last-mid)%2==1)
                    first=mid+1;
                else
                    last=mid;
            }
        }
        return nums[first];

    }
};