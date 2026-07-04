// Approach
// 1. XOR operation di property use kraange.
// 2. Same numbers da XOR hamesha 0 hunda hai.
// 3. 0 da kise vi number naal XOR ohi number hunda hai.
// 4. Saare elements da XOR karde jaavaange.
// 5. Jehde numbers do vaar aunde ne,
//    oh ik duje nu cancel kar denge.
// 6. Aakhir ch sirf single number hi bachuga,
//    ohi answer hovega.

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int ans=0;

        for(int i=0;i<nums.size();i++)
        {
            ans=ans^nums[i];
        }

        return ans;
    }
};
