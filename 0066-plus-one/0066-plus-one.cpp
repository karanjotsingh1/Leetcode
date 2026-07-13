class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();

        

        digits[n-1]+=1;
        int carry =0;

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
                digits[idx]+=1;
                carry=0;
                break;
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