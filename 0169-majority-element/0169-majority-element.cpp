// Approach
// 1. Pehlaa aapaa first element nu majority candidate mann laavaange.
// 2. Ik frequency variable rakhange jo current candidate da vote count store kru ga.
// 3. Je current element candidate de equal hove,
//    ta frequency increase kr devaange.
// 4. Nahi ta frequency decrease kr devaange.
// 5. Je frequency 0 ho jaave,
//    ta current element nu nava candidate bna devaange
//    te frequency nu 1 kr devaange.
// 6. Last ch majority candidate hi answer houga.

class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        int n=nums.size();

        if(n==1)
        {
            return nums[0];
        }

        int majority_ele=0;
        int freq=1;

        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[majority_ele])
            {
                freq++;
            }
            else
            {
                freq--;

                if(freq==0)
                {
                    majority_ele=i;
                    freq=1;
                }
            }
        }

        return nums[majority_ele];
    }
};