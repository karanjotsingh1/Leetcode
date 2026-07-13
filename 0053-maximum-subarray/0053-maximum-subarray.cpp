// Approach
// 1. Ik variable (curr_sum) maintain karaange,
//    jo current subarray da sum store karega.
// 2. Ik hor variable (max_sum) maintain karaange,
//    jo maximum subarray sum store karega.
// 3. Array nu ik vaar traverse karaange.
// 4. Har element nu current sum ch add karaange.
// 5. Current sum naal maximum sum update karaange.
// 6. Je current sum negative ho jaave,
//    ta usnu 0 kar devaange,
//    kyunki negative sum future subarray nu sirf ghataega.
// 7. Traversal complete hon to baad
//    maximum subarray sum return karaange.

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int n=nums.size();

        if(n==1)
        {
            return nums[0];
        }

        int max_sum=INT_MIN;

        int curr_sum=0;

        for(int i=0;i<n;i++)
        {
            curr_sum+=nums[i];

            max_sum=max(max_sum,curr_sum);

            if(curr_sum<0)
            {
                curr_sum=0;
            }
        }

        return max_sum;
    }
};