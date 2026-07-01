// Approach
// 1. Pehlaa check kraange je array empty aa ya sirf ik element aa,
//    ta sidha size return kr devaange.
// 2. Ik idx pointer rakhange jo next unique element di position dassu ga.
// 3. Hun array nu second element ton traverse kraange.
// 4. Je current element previous element ton different hove,
//    ta onu idx position te rakh devaange te idx agge move kraange.
// 5. Je current element duplicate hove,
//    ta onu ignore kr devaange.
// 6. Last ch idx hi unique elements di count hougi te onu return kr devaange.

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int n=nums.size();

        if(n==0||n==1)
        {
            return n;
        }

        int idx=1;

        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                nums[idx]=nums[i];
                idx++;
            }
        }

        return idx;
    }
};