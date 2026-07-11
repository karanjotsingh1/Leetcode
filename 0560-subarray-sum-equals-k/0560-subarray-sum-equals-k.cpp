// Approach
// 1. Prefix sum maintain karaange.
// 2. Ik unordered_map use karaange,
//    jithe key = prefix sum
//    te value = us prefix sum di frequency hovegi.
// 3. Initially map ch (0,1) store karaange,
//    kyunki prefix sum 0 ik vaar starting ton pehla exist karda hai.
// 4. Har element te current prefix sum calculate karaange.
// 5. Required prefix sum = currentPrefix - k calculate karaange.
// 6. Je eh required prefix sum pehla map ch exist karda hove,
//    ta usdi frequency answer ch add karaange,
//    kyunki ohna saare indices ton current index tak
//    subarray da sum k de equal hovega.
// 7. Current prefix sum di frequency map ch increase karaange.
// 8. Saare elements traverse karan to baad
//    total count return karaange.

class Solution
{
public:
    int subarraySum(vector<int>& nums,int k)
    {
        unordered_map<int,int>m;

        m[0]=1;

        int prefix_sum=0;
        int count=0;

        for(int i=0;i<nums.size();i++)
        {
            prefix_sum+=nums[i];

            int remaining=prefix_sum-k;

            count+=m[remaining];

            m[prefix_sum]++;
        }

        return count;
    }
};