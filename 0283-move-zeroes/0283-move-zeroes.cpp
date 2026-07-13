// Approach
// 1. Pehla array ch total zeroes count karaange.
// 2. Ik pointer (idx) maintain karaange,
//    jo next non-zero element di position represent karega.
// 3. Array nu ik vaar traverse karaange.
// 4. Je current element non-zero hove,
//    ta usnu idx position te place karaange
//    te idx nu increment karaange.
// 5. Saare non-zero elements place hon to baad,
//    remaining positions te zero fill karaange.
// 6. Is tarah saare non-zero elements
//    apni relative order ch rehnde ne
//    te saare zeroes end ch move ho jaande ne.

class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        int n=nums.size();

        int count=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                count++;
            }
        }

        int idx=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                nums[idx]=nums[i];
                idx++;
            }
        }

        while(count--)
        {
            nums[idx]=0;
            idx++;
        }
    }
};