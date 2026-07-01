// Approach
// 1. Pehlaa aapaa right to left traverse kraange te pivot labhaange.
//    Pivot oh index houga jithe nums[i]<nums[i+1] hove.
//    Eh dassda ki itho next greater permutation possible aa.
//
// 2. Je pivot na mile, matlab poora array descending order ch aa.
//    Eh largest permutation aa, is karke sirf reverse krke smallest permutation bna devaange.
//
// 3. Je pivot mil gya, hun right side ton pehlaa element labhaange
//    jo pivot value ton vadda hove.
//    Eh smallest greater element houga jo next permutation bnaun ch help kruga.
//
// 4. Hun pivot te oh element swap kr devaange.
//    Is naal pivot value thodi vaddi ho jaegi.
//
// 5. Swap to baad pivot de right wala part hale vi descending order ch houga.
//    Is karke us suffix nu reverse kr devaange taaki oh ascending ban jaave
//    te sanu next immediate permutation mil jaave.
//
// 6. In-place hi saara kaam ho jaega, koi extra array di lod nhi.

class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        int n=nums.size();
        int pivot=-1;

        // Find the pivot
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                pivot=i;
                break;
            }
        }

        // If no pivot exists, current permutation is the largest
        if(pivot==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }

        // Find the next greater element from the right
        for(int i=n-1;i>pivot;i--)
        {
            if(nums[i]>nums[pivot])
            {
                swap(nums[i],nums[pivot]);
                break;
            }
        }

        // Reverse the suffix to get the smallest possible order
        reverse(nums.begin()+pivot+1,nums.end());
    }
};