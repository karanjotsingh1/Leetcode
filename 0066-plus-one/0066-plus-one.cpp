// Approach
// 1. Last digit ch 1 add karaange.
// 2. Je last digit 10 ban jaave,
//    ta usnu 0 bana ke carry generate karaange.
// 3. Carry nu left side propagate karaange.
// 4. Jadon tak carry hove,
//    har digit check karaange.
// 5. Je digit 9 hove,
//    ta usnu 0 bana ke carry continue rakhaange.
// 6. Je digit 9 na hove,
//    ta usnu 1 increase karaange
//    te carry khatam kar devaange.
// 7. Je saari digits process hon to baad vi carry bach jaave,
//    ta beginning ch 1 insert karaange.
// 8. Updated array return karaange.

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int n=digits.size();

        digits[n-1]++;

        int carry=0;

        if(digits[n-1]==10)
        {
            digits[n-1]=0;
            carry=1;
        }

        int idx=n-2;

        while(idx>=0 && carry==1)
        {
            if(digits[idx]==9)
            {
                digits[idx]=0;
            }
            else
            {
                digits[idx]++;
                carry=0;
            }

            idx--;
        }

        if(carry==1)
        {
            digits.insert(digits.begin(),1);
        }

        return digits;
    }
};