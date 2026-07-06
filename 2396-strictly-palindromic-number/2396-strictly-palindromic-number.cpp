class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for(int i=2;i<=n-2;i++)
        {
            string ans="";
            int nn=n;
            while(nn>0)
            {
                int last=nn%i;
                ans+=to_string(last);
                nn=nn/i;
            }
            int left=0;
            int right=ans.size()-1;
            while(left<right)
            {
                if(left!=right)
                    return false;

                left++;
                right--;
            }

        }
        return true;
    }
};