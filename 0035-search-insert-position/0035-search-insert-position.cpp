// Approach
// 1. Binary Search use kraange.
// 2. Je target middle element de equal hove,
//    ta usda index return kar devaange.
// 3. Je target middle element ton vadda hove,
//    ta right half ch search kraange.
// 4. Je target middle element ton chhota hove,
//    ta left half ch search kraange.
// 5. Jadon loop khatam hove,
//    ta left hi target di correct insertion position hovegi.

class Solution
{
public:
    int searchInsert(vector<int>& nums,int target)
    {
        int left=0;
        int right=nums.size()-1;

        while(left<=right)
        {
            int mid=left+(right-left)/2;

            if(nums[mid]==target)
            {
                return mid;
            }

            if(nums[mid]<target)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }

        return left;
    }
};