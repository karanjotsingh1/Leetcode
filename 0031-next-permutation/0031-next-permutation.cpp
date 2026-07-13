// Approach
// 1. Right to left traverse karke
//    pehla aisa index (pivot) find karaange
//    jithe nums[i] < nums[i+1] hove.
// 2. Je aisa koi pivot na mile,
//    matlab array descending order ch hai,
//    ta smallest permutation banaan lai
//    poori array reverse (ya sort) kar devaange.
// 3. Je pivot mil jaave,
//    ta right side ton pehla aisa element find karaange
//    jo pivot element ton vadda hove.
// 4. Pivot te us element nu swap karaange.
// 5. Pivot de right wala part descending order ch hunda hai,
//    is karke usnu reverse kar devaange,
//    taaki smallest possible permutation mil jaave.
// 6. Updated array hi next permutation hovegi.

class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        int n=nums.size();

        if(n==0)
        {
            return;
        }

        int pivot=-1;

        // Find pivot
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                pivot=i;
                break;
            }
        }

        // Last permutation
        if(pivot==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }

        // Find next greater element
        for(int i=n-1;i>pivot;i--)
        {
            if(nums[i]>nums[pivot])
            {
                swap(nums[i],nums[pivot]);
                break;
            }
        }

        // Reverse the suffix
        int left=pivot+1;
        int ryt=n-1;

        while(left<ryt)
        {
            swap(nums[left],nums[ryt]);
            left++;
            ryt--;
        }
    }
};