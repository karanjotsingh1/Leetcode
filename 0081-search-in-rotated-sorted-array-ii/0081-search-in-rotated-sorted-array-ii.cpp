// Approach
// 1. Binary Search use karaange.
// 2. Har iteration ch middle element calculate karaange.
// 3. Je middle element target de equal hove,
//    ta true return karaange.
// 4. Je left, middle te right tino equal hon,
//    ta sorted half identify nahi ho sakdi.
//    Is karke left++ te right-- karaange.
// 5. Nahi ta check karaange
//    ki left half sorted hai ya right half.
// 6. Je left half sorted hove,
//    te target usde range ch hove,
//    ta left half ch search karaange.
//    Nahi ta right half ch search karaange.
// 7. Je right half sorted hove,
//    te target usde range ch hove,
//    ta right half ch search karaange.
//    Nahi ta left half ch search karaange.
// 8. Je Binary Search complete ho jaave
//    te target na mile,
//    ta false return karaange.

class Solution
{
public:
    bool search(vector<int>& nums,int target)
    {
        int n=nums.size();

        int left=0;
        int ryt=n-1;

        while(left<=ryt)
        {
            int mid=left+(ryt-left)/2;

            if(nums[mid]==target)
            {
                return true;
            }

            // Cannot determine sorted half
            if(nums[left]==nums[mid] && nums[mid]==nums[ryt])
            {
                left++;
                ryt--;
            }
            // Left half sorted
            else if(nums[left]<=nums[mid])
            {
                if(target>=nums[left] && target<nums[mid])
                {
                    ryt=mid-1;
                }
                else
                {
                    left=mid+1;
                }
            }
            // Right half sorted
            else
            {
                if(target>nums[mid] && target<=nums[ryt])
                {
                    left=mid+1;
                }
                else
                {
                    ryt=mid-1;
                }
            }
        }

        return false;
    }
};