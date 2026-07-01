// Approach
// 1. Pehlaa aapaa array nu sort kr devaange taaki two pointer technique use ho sake
//    te duplicates easily skip ho jaan.
// 2. Hun har element nu ik ik karke first element mann ke fix kraange.
// 3. Baaki do elements lai left te right pointers use kraange.
// 4. Je tinna da sum 0 ton chhota hove,
//    ta left++ kraange.
//    Je sum 0 ton vadda hove,
//    ta right-- kraange.
// 5. Je sum exactly 0 hove,
//    ta triplet answer ch store kraange.
// 6. Triplet miln to baad left te right de duplicate elements skip kraange
//    taaki same triplet dubara answer ch na aave.
// 7. Har iteration ch first element(i) de duplicates vi skip kraange.

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());

        int n=nums.size();
        vector<vector<int>>ans;

        for(int i=0;i<n-2;i++)
        {
            // Skip duplicate first elements
            if(i>0&&nums[i]==nums[i-1])
            {
                continue;
            }

            int left=i+1;
            int right=n-1;

            while(left<right)
            {
                int sum=nums[i]+nums[left]+nums[right];

                if(sum<0)
                {
                    left++;
                }
                else if(sum>0)
                {
                    right--;
                }
                else
                {
                    ans.push_back({nums[i],nums[left],nums[right]});

                    left++;
                    right--;

                    // Skip duplicate second elements
                    while(left<right&&nums[left]==nums[left-1])
                    {
                        left++;
                    }

                    // Skip duplicate third elements
                    while(left<right&&nums[right]==nums[right+1])
                    {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};