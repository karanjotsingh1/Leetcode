// Approach
// 1. Array sorted hai,
//    is karke duplicate elements continuously aunge.
// 2. Array nu ik vaar traverse karaange.
// 3. Har unique element di frequency count karaange.
// 4. Je frequency 2 ya us ton vadh hove,
//    ta us element nu answer array ch sirf 2 vaar store karaange.
// 5. Je frequency 1 hove,
//    ta usnu ik vaar store karaange.
// 6. Ik pointer (idx) maintain karaange,
//    jo next valid position dasega.
// 7. Traversal complete hon to baad
//    idx hi modified array di length hovegi.

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int n=nums.size();

        int idx=0;

        for(int i=0;i<n;i++)
        {
            int ele=nums[i];

            int count=1;

            while(i+1<n && nums[i+1]==ele)
            {
                count++;
                i++;
            }

            if(count>=2)
            {
                nums[idx++]=ele;
                nums[idx++]=ele;
            }
            else
            {
                nums[idx++]=ele;
            }
        }

        return idx;
    }
};