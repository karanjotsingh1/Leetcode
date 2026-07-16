// Approach
// 1. Do variables (ones te twos) maintain karaange.
// 2. Ones oh bits store karega
//    jo exactly ik vaar appear hoye ne.
// 3. Twos oh bits store karega
//    jo exactly do vaar appear hoye ne.
// 4. Jadon koi bit teesri vaar aundi hai,
//    ta oh ones te twos dono ton remove ho jaandi hai.
// 5. Is tarah har bit da count
//    modulo 3 maintain hunda hai.
// 6. Traversal complete hon to baad,
//    ones ch sirf unique number di bits bachdiyan ne.
// 7. Ones return karaange.

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int ones=0;
        int twos=0;

        for(int number:nums)
        {
            ones=(ones^number) & (~twos);

            twos=(twos^number) & (~ones);
        }

        return ones;
    }
};