// Approach
// 1. Array nu sort karaange,
//    taaki Two Pointer technique apply ho sake
//    te duplicates easily skip ho jaan.
// 2. Har element nu triplet da first element maan ke iterate karaange.
// 3. Je current element previous element de equal hove,
//    ta usnu skip karaange,
//    kyunki duplicate triplets aa jaan ge.
// 4. Current element lai
//    left pointer = i+1
//    te ryt pointer = last index set karaange.
// 5. Current triplet da sum calculate karaange.
// 6. Je sum 0 hove,
//    ta triplet answer ch add karaange.
// 7. Fer left te ryt nu move karaange
//    te duplicate elements nu skip karaange.
// 8. Je sum 0 ton chhota hove,
//    ta left pointer increase karaange,
//    taaki sum vad sake.
// 9. Je sum 0 ton vadda hove,
//    ta ryt pointer decrease karaange,
//    taaki sum ghatt sake.
// 10. Saare unique triplets mil jaan to baad
//     answer return karaange.

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;

        int n=nums.size();

        for(int i=0;i<n-2;i++)
        {
            // Skip duplicate first elements
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }

            int left=i+1;
            int ryt=n-1;

            while(left<ryt)
            {
                int sum=nums[i]+nums[left]+nums[ryt];

                if(sum==0)
                {
                    ans.push_back({nums[i],nums[left],nums[ryt]});

                    left++;
                    ryt--;

                    // Skip duplicate left elements
                    while(left<ryt && nums[left]==nums[left-1])
                    {
                        left++;
                    }

                    // Skip duplicate right elements
                    while(left<ryt && nums[ryt]==nums[ryt+1])
                    {
                        ryt--;
                    }
                }
                else if(sum<0)
                {
                    left++;
                }
                else
                {
                    ryt--;
                }
            }
        }

        return ans;
    }
};