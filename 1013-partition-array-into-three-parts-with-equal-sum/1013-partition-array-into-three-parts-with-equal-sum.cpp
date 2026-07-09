// Approach
// 1. Pura array da total sum calculate karaange.
// 2. Je total sum 3 naal divisible na hove,
//    ta 3 equal parts possible nahi,
//    is karke false return karaange.
// 3. Target sum = totalSum/3 calculate karaange.
// 4. Array nu ik vaar traverse karaange.
// 5. Running sum maintain karaange.
// 6. Jadon running sum target de equal ho jaave,
//    ik part mil gaya.
//    Count increase karaange te running sum dubara 0 kar devaange.
// 7. Je traversal de end tak
//    3 ya us ton zyada parts mil jaan,
//    ta true return karaange.
// 8. Nahi ta false return karaange.

class Solution
{
public:
    bool canThreePartsEqualSum(vector<int>& arr)
    {
        int total=0;

        for(int x:arr)
        {
            total+=x;
        }

        if(total%3!=0)
        {
            return false;
        }

        int target=total/3;

        int sum=0;
        int count=0;

        for(int x:arr)
        {
            sum+=x;

            if(sum==target)
            {
                count++;
                sum=0;
            }
        }

        return count>=3;
    }
};