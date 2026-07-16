class Solution {
public:
    string bits(int num)
    {
        if(num==0)
            return "0";

        string ans="";
        while(num>0)
        {
            int last=num%2;
            ans=to_string(last)+ans;
            num=num/2;
        }
        return ans;

    }
    int minBitFlips(int start, int goal) {
        string bit1=bits(start);
        string bit2=bits(goal);

        int n=bit1.size();
        int m=bit2.size();

        if(n>m)
        {
            int diff=n-m;
            for(int i=1;i<=diff;i++)
            {
                bit2="0"+bit2;
            }
        }
        else
        {
            int diff=m-n;
            for(int i=1;i<=diff;i++)
            {
                bit1="0"+bit1;
            }
        }

        n=bit1.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(bit1[i]!=bit2[i])
            {
                ans+=1;
            }
        }
        return ans;

    }
};