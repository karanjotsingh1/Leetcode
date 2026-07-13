// Approach
// 1. Array ch numbers 0 to n tak hone chahide ne,
//    jithe ik number missing hai.
// 2. 1 to n tak da expected sum calculate karaange.
//    (0 add karan naal koi difference nahi painda.)
// 3. Array de saare elements da actual sum calculate karaange.
// 4. Expected sum chon actual sum subtract karaange.
// 5. Remaining value hi missing number hovegi.

class Solution
{
public:
    int missingNumber(vector<int>& nums)
    {
        int n=nums.size();

        int expected_sum=0;

        for(int i=1;i<=n;i++)
        {
            expected_sum+=i;
        }

        int actual_sum=0;

        for(int i=0;i<n;i++)
        {
            actual_sum+=nums[i];
        }

        return expected_sum-actual_sum;
    }
};