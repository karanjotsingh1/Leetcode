// Approach
// 1. nums1 te nums2 de saare possible sums calculate kraange.
// 2. Har sum di frequency unordered_map ch store kraange.
// 3. Hun nums3 te nums4 de saare possible sums calculate kraange.
// 4. Har sum lai -(sum) map ch search kraange.
// 5. Je -(sum) map ch exist karda hove,
//    ta usdi frequency answer ch add kar devaange.
// 6. Aakhir ch total count return kar devaange.

class Solution
{
public:
    int fourSumCount(vector<int>& nums1,vector<int>& nums2,vector<int>& nums3,vector<int>& nums4)
    {
        unordered_map<int,int>mp;

        int n=nums1.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[nums1[i]+nums2[j]]++;
            }
        }

        int count=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int target=-(nums3[i]+nums4[j]);

                if(mp.find(target)!=mp.end())
                {
                    count+=mp[target];
                }
            }
        }

        return count;
    }
};