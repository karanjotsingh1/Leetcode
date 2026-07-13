// Approach
// 1. Unordered_set use karaange
//    unique elements store karan lai.
// 2. Array nu ik vaar traverse karaange.
// 3. Har current element lai check karaange
//    ki oh pehla set ch present hai ya nahi.
// 4. Je present hove,
//    matlab duplicate element mil gaya.
//    Immediately true return karaange.
// 5. Je present na hove,
//    ta current element nu set ch insert karaange.
// 6. Je poora array traverse ho jaave
//    te koi duplicate na mile,
//    ta false return karaange.

class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> st;

        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i])!=st.end())
            {
                return true;
            }

            st.insert(nums[i]);
        }

        return false;
    }
};