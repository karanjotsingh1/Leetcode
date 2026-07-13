// Approach
// 1. Do Binary Searches perform karaange.
// 2. First Binary Search ch
//    target di first occurrence find karaange.
// 3. Je target mil jaave,
//    ta answer update karke
//    left side search continue karaange,
//    taaki hor pehli occurrence mil sake.
// 4. Second Binary Search ch
//    target di last occurrence find karaange.
// 5. Je target mil jaave,
//    ta answer update karke
//    right side search continue karaange,
//    taaki hor last occurrence mil sake.
// 6. Je target array ch na hove,
//    ta first te last dono -1 rehange.
// 7. Finally {first,last} return karaange.

class Solution
{
public:
    vector<int> searchRange(vector<int>& nums,int target)
    {
        int n=nums.size();

        int first=-1;
        int last=-1;

        int left=0;
        int ryt=n-1;

        // Find first occurrence
        while(left<=ryt)
        {
            int mid=left+(ryt-left)/2;

            if(nums[mid]<target)
            {
                left=mid+1;
            }
            else if(nums[mid]>target)
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

        // Find last occurrence
        while(left<=ryt)
        {
            int mid=left+(ryt-left)/2;

            if(nums[mid]<target)
            {
                left=mid+1;
            }
            else if(nums[mid]>target)
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