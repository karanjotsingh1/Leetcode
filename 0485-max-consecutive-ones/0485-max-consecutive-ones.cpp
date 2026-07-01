// Approach
// 1. Pehlaa aapaa do variables rakhange:
//    curr current consecutive 1's count lai
//    te maxi maximum consecutive 1's lai.
// 2. Hun array nu left to right traverse kraange.
// 3. Je current element 1 hove,
//    ta curr increase kraange te maxi update kraange.
// 4. Je current element 0 hove,
//    ta consecutive sequence break ho jaandi aa,
//    is karke curr nu 0 kr devaange.
// 5. Last ch maxi hi maximum consecutive 1's houga.

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int curr=0;
        int maxi=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                curr++;

                // Update the maximum streak of 1's
                maxi=max(maxi,curr);
            }
            else
            {
                curr=0;
            }
        }

        return maxi;
    }
};