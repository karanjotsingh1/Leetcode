// Approach
// 1. Prefix sum maintain kraange.
// 2. Prefix sum di parity (Odd ya Even) hi important hai.
// 3. Do counters maintain kraange:
//    even -> kinne even prefix sums aaye ne.
//    odd -> kinne odd prefix sums aaye ne.
// 4. Initially even=1 hovega,
//    kyunki empty prefix da sum 0 (even) hunda hai.
// 5. Har element add karke current prefix sum calculate kraange.
// 6. Je current prefix sum even hove,
//    ta har previous odd prefix naal odd subarray banegi.
//    Is karke answer ch odd add kar devaange.
// 7. Je current prefix sum odd hove,
//    ta har previous even prefix naal odd subarray banegi.
//    Is karke answer ch even add kar devaange.
// 8. Current prefix di parity de according
//    even ya odd counter update karaange.
// 9. Aakhir ch answer return kar devaange.

class Solution
{
public:
    int numOfSubarrays(vector<int>& arr)
    {
        const int MOD=1000000007;

        long long ans=0;

        int prefix=0;

        int even=1;
        int odd=0;

        for(int i=0;i<arr.size();i++)
        {
            prefix+=arr[i];

            if(prefix%2==0)
            {
                ans=(ans+odd)%MOD;
                even++;
            }
            else
            {
                ans=(ans+even)%MOD;
                odd++;
            }
        }

        return ans;
    }
};