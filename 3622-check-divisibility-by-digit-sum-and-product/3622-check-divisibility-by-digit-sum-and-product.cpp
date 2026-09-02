class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int prod=1;
        int nn=n;

        while(nn>0)
        {
            int last=nn%10;
            sum+=last;
            prod*=last;

            nn=nn/10;
        }

        sum+=prod;

        return n%sum==0;
    }
};