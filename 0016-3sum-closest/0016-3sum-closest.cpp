// Approach
// 1. Array nu sort karaange,
//    taaki Two Pointer technique apply ho sake.
// 2. Pehle tin elements da sum
//    initial closest answer maan lavaange.
// 3. Har element nu first element of triplet maan ke iterate karaange.
// 4. Current element lai
//    left = i+1
//    te ryt = last index set karaange.
// 5. Current triplet da sum calculate karaange.
// 6. Je current sum target de hor close hove,
//    ta closest answer update karaange.
// 7. Je current sum target de equal hove,
//    ta immediately target return karaange,
//    kyunki is ton better answer possible nahi.
// 8. Je current sum target ton chhota hove,
//    ta left pointer increase karaange,
//    taaki sum vad sake.
// 9. Je current sum target ton vadda hove,
//    ta ryt pointer decrease karaange,
//    taaki sum ghatt sake.
// 10. Traversal complete hon to baad
//     closest sum return karaange.

class Solution
{
public:
    int threeSumClosest(vector<int>& nums,int target)
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int closest=nums[0]+nums[1]+nums[2];

        for(int i=0;i<n-2;i++)
        {
            int left=i+1;
            int ryt=n-1;

            while(left<ryt)
            {
                int sum=nums[i]+nums[left]+nums[ryt];

                if(abs(sum-target)<abs(closest-target))
                {
                    closest=sum;
                }

                if(sum==target)
                {
                    return target;
                }
                else if(sum<target)
                {
                    left++;
                }
                else
                {
                    ryt--;
                }
            }
        }

        return closest;
    }
};