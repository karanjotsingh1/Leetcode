// Approach
// 1. XOR operation use karaange.
// 2. XOR di property hundi hai:
//    (a ^ a = 0)
//    (a ^ 0 = a)
// 3. Array de saare elements da XOR calculate karaange.
// 4. Jis element di occurrence 2 vaar hovegi,
//    oh XOR karke cancel ho jaavega.
// 5. Sirf oh element bachuga
//    jisdi occurrence ik vaar hai.
// 6. Final XOR value return karaange.

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int n=nums.size();

        if(n==1)
        {
            return nums[0];
        }

        int x_o_r=nums[0];

        for(int i=1;i<n;i++)
        {
            x_o_r=x_o_r^nums[i];
        }

        return x_o_r;
    }
};