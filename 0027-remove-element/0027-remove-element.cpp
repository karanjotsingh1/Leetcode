// Approach
// 1. Ik pointer (idx) maintain karaange,
//    jo next valid element di position represent karega.
// 2. Array nu ik vaar traverse karaange.
// 3. Je current element val de equal na hove,
//    ta usnu idx position te store karaange.
// 4. Fer idx nu increment karaange.
// 5. Je current element val de equal hove,
//    ta usnu ignore karaange.
// 6. Traversal complete hon to baad,
//    idx hi remaining valid elements di count hovegi.
// 7. idx return karaange.

class Solution
{
public:
    int removeElement(vector<int>& nums,int val)
    {
        int n=nums.size();

        if(n==0)
        {
            return 0;
        }

        int idx=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]!=val)
            {
                nums[idx]=nums[i];
                idx++;
            }
        }

        return idx;
    }
};