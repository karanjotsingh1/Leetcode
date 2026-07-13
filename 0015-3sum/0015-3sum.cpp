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

                    while(left<ryt && nums[left]==nums[left-1])
                    {
                        left++;
                    }

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