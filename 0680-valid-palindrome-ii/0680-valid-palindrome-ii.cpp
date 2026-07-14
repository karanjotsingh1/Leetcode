class Solution {
public:
    bool valid_palin(string s,int left,int ryt)
    {
        while(left<ryt)
        {
            if(s[left]!=s[ryt])
                return false;

            left++;
            ryt--;

        }
            return true;
    }

    bool validPalindrome(string s) {
        int count=0;

        int i=0;
        int j=s.size()-1;

        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                if(valid_palin(s,i,j-1)==false && valid_palin(s,i+1,j)==false)
                    return false;
                else
                    return true;
            }
        }
        return true;
    }
};