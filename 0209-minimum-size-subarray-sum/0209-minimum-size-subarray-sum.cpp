// Approach
// 1. Do pointers use karaange:
//    left te right,
//    jo current window represent karange.
// 2. Right pointer nu move karke
//    current window da sum maintain karaange.
// 3. Jadon window da sum
//    target ton vadda ya equal ho jaave,
//    ta current window valid hai.
// 4. Window di length calculate karke
//    minimum answer update karaange.
// 5. Hun left pointer move karaange
//    te left element nu sum chon subtract karaange,
//    taaki hor chhoti valid window mil sake.
// 6. Eh process repeat karaange
//    jadon tak sum target ton chhota na ho jaave.
// 7. Fer right pointer nu agge move karaange.
// 8. Je koi valid window na mile,
//    ta 0 return karaange.
// 9. Nahi ta minimum window length return karaange.

class Solution
{
public:
    int minSubArrayLen(int target,vector<int>& nums)
    {
        int n=nums.size();

        int left=0;

        int sum=0;

        int mini=INT_MAX;

        for(int right=0;right<n;right++)
        {
            sum+=nums[right];

            while(sum>=target)
            {
                mini=min(mini,right-left+1);

                sum-=nums[left];

                left++;
            }
        }

        if(mini==INT_MAX)
        {
            return 0;
        }

        return mini;
    }
};