// Approach
// 1. Pehlaa binary search use kraange.
// 2. Har mid te check kraange ki current element single aa ja pair da part.
// 3. Je single mil jaave,
//    ta onu return kr devaange.
// 4. Je pair right side(mid+1) naal bnda aa,
//    ta right side ch kinne elements ne ohdi parity check kraange.
//    Odd elements hon ta single left side ch houga,
//    nahi ta right side ch houga.
// 5. Je pair left side(mid-1) naal bnda aa,
//    ta ohi parity logic use kraange.
// 6. Binary search complete hon to baad first index hi answer houga.

class Solution
{
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        int n=nums.size();

        if(n==1)
        {
            return nums[0];
        }

        int first=0;
        int last=n-1;

        while(first<last)
        {
            int mid=first+(last-first)/2;

            if((mid==0||nums[mid]!=nums[mid-1])&&(mid==n-1||nums[mid]!=nums[mid+1]))
            {
                return nums[mid];
            }

            if(mid+1<n&&nums[mid]==nums[mid+1])
            {
                if((last-mid)%2==1)
                {
                    last=mid-1;
                }
                else
                {
                    first=mid+2;
                }
            }
            else
            {
                if((last-mid)%2==1)
                {
                    first=mid+1;
                }
                else
                {
                    last=mid-2;
                }
            }
        }

        return nums[first];
    }
};