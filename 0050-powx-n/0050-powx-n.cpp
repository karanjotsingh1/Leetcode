class Solution {
public:
    double myPow(double x, int n) {
        long nn=n;
        if(nn<0)
        {
            x=1/x;
            nn=nn*-1;
        }
        if(x==0)    
            return 0;
        double answer=1;
        

        while(nn>0)
        {
            int last=nn%2;
            if(last==1)
            {
                answer*=x;
            }
            x=x*x;

            nn=nn/2;
        }
        return answer;
    }
};