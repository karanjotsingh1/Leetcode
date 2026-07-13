// Approach
// 1. Tin pointers maintain karaange:
//    low, mid te high.
// 2. low de left side
//    saare 0's honge.
// 3. high de right side
//    saare 2's honge.
// 4. mid current element nu traverse karega.
// 5. Je nums[mid] == 0 hove,
//    ta usnu low naal swap karaange,
//    fer low te mid dono increase karaange.
// 6. Je nums[mid] == 1 hove,
//    ta oh already correct position te hai,
//    is karke sirf mid increase karaange.
// 7. Je nums[mid] == 2 hove,
//    ta usnu high naal swap karaange,
//    fer high decrease karaange.
//    Mid nu increase nahi karaange,
//    kyunki swap hoke nava element aaya hai,
//    usnu dubara check karna zaroori hai.
// 8. Jadon mid high ton vadda ho jaave,
//    traversal complete ho jaavegi
//    te array sorted hovegi.

class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int n=nums.size();

        int low=0;
        int mid=0;
        int high=n-1;

        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};