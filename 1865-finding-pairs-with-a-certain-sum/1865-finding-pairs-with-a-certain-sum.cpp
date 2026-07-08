// Approach
// 1. nums1 te nums2 nu index-wise store kraange.
// 2. nums2 de elements di frequency unordered_map ch maintain kraange.
// 3. add(index,val) ch
//    pehla old value di frequency ghataange.
// 4. Fir nums2[index] update kraange.
// 5. Update hon to baad new value di frequency vadhaange.
// 6. count(tot) ch
//    nums1 de har element lai
//    required value = tot-current element calculate kraange.
// 7. Je required value nums2 di frequency map ch exist kardi hove,
//    ta usdi frequency answer ch add kar devaange.
// 8. Aakhir ch total pairs return kar devaange.

class FindSumPairs
{
public:
    unordered_map<int,int>nums1Map;
    unordered_map<int,int>nums2Map;
    unordered_map<int,int>freq;

    FindSumPairs(vector<int>& nums1,vector<int>& nums2)
    {
        for(int i=0;i<nums1.size();i++)
        {
            nums1Map[i]=nums1[i];
        }

        for(int i=0;i<nums2.size();i++)
        {
            nums2Map[i]=nums2[i];
            freq[nums2[i]]++;
        }
    }

    void add(int index,int val)
    {
        freq[nums2Map[index]]--;

        nums2Map[index]+=val;

        freq[nums2Map[index]]++;
    }

    int count(int tot)
    {
        int ans=0;

        for(auto it:nums1Map)
        {
            int need=tot-it.second;

            if(freq.find(need)!=freq.end())
            {
                ans+=freq[need];
            }
        }

        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */