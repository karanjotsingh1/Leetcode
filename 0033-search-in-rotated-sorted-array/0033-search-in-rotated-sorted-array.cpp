// Approach
// 1. Pehlaa normal binary search vangu mid calculate kraange.
// 2. Je mid te target mil jaave,
//    ta index return kr devaange.
// 3. Har iteration ch ik half hamesha sorted hundi aa.
// 4. Je left half sorted aa,
//    ta check kraange ki target left half di range ch aa ja nahi.
//    Je aa, ta left search kraange.
//    Nahi ta right search kraange.
// 5. Je right half sorted aa,
//    ta check kraange ki target right half di range ch aa ja nahi.
//    Je aa, ta right search kraange.
//    Nahi ta left search kraange.
// 6. Jadon binary search khatam ho jaave,
//    matlab target present nhi aa, -1 return kr devaange.

class Solution
{
public:
    int search(vector<int>& nums,int target)
    {
        int n=nums.size();

        int i=0;
        int j=n-1;

        while(i<=j)
        {
            int mid=i+(j-i)/2;

            if(nums[mid]==target)
            {
                return mid;
            }

            // Left half is sorted
            if(nums[i]<=nums[mid])
            {
                if(nums[i]<=target && target<nums[mid])
                {
                    j=mid-1;
                }
                else
                {
                    i=mid+1;
                }
            }
            // Right half is sorted
            else
            {
                if(nums[mid]<target && target<=nums[j])
                {
                    i=mid+1;
                }
                else
                {
                    j=mid-1;
                }
            }
        }

        return -1;
    }
};