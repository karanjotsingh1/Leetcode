// Approach
// 1. Pehlaa aapaa array nu sort kr devaange taaki duplicates easily skip ho jaan.
// 2. Hun pehle do numbers(i te j) nu fixed rakhange using nested loops.
// 3. Baaki do numbers lai two pointers(left te right) use kraange.
// 4. Je sum target ton chhota hove ta left++ kraange.
//    Je sum target ton vadda hove ta right-- kraange.
// 5. Je sum target de equal hove ta quadruplet answer ch store kraange
//    te duplicates skip krke pointers move kraange.
// 6. Har level(i,j,left,right) te duplicates skip krna bahut zaroori aa
//    taaki unique quadruplets hi answer ch aun.
// 7. Long long use kraange taaki integer overflow na hove.

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums,int target)
    {
        sort(nums.begin(),nums.end());

        int n=nums.size();
        vector<vector<int>>ans;

        for(int i=0;i<n-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
            {
                continue;
            }

            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1])
                {
                    continue;
                }

                int left=j+1;
                int right=n-1;

                while(left<right)
                {
                    long long sum=(long long)nums[i]+nums[j]+nums[left]+nums[right];

                    if(sum<target)
                    {
                        left++;
                    }
                    else if(sum>target)
                    {
                        right--;
                    }
                    else
                    {
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});

                        left++;
                        right--;

                        // Skip duplicate third element
                        while(left<right&&nums[left]==nums[left-1])
                        {
                            left++;
                        }

                        // Skip duplicate fourth element
                        while(left<right&&nums[right]==nums[right+1])
                        {
                            right--;
                        }
                    }
                }
            }
        }

        return ans;
    }
};