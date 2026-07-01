// Approach
// 1. Pehlaa aapaa ik variable(currSum) rakhange jo current subarray da sum store kru ga.
// 2. Ik hor variable(maxSum) rakhange jo hun takk da maximum sum store kru ga.
// 3. Hun array nu left to right traverse kraange.
// 4. Har element nu currSum ch add kraange te check kraange ki maxSum update hunda aa ja nahi.
// 5. Je currSum negative ho jaave, ta usnu 0 kr devaange,
//    kyunki negative sum future subarray nu sirf chhota hi karega.
// 6. Last ch maxSum hi maximum subarray sum houga.

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int currSum=0;
        int maxSum=nums[0];

        for(int i=0;i<nums.size();i++)
        {
            currSum+=nums[i];

            // Update maximum sum found so far
            maxSum=max(maxSum,currSum);

            // Start a new subarray if current sum becomes negative
            if(currSum<0)
            {
                currSum=0;
            }
        }

        return maxSum;
    }
};