// Approach
// 1. Pehlaa aapaa Roman symbols di value map ch store kraange.
// 2. Hun string nu left to right traverse kraange.
// 3. Har character nu usde next character naal compare kraange.
// 4. Je current value next value ton chhoti hove,
//    matlab subtraction case aa (IV, IX, XL...),
//    ta current value answer cho subtract kr devaange.
// 5. Nahi ta current value answer ch add kr devaange.
// 6. Last character da next element hunda nhi,
//    is karke onu separately answer ch add kraange.
// 7. Last ch final integer answer return kr devaange.

class Solution
{
public:
    int romanToInt(string s)
    {
        map<char,int>m;

        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;

        int ans=0;
        int n=s.size();

        for(int i=0;i<n-1;i++)
        {
            if(m[s[i]]<m[s[i+1]])
            {
                ans-=m[s[i]];
            }
            else
            {
                ans+=m[s[i]];
            }
        }

        ans+=m[s[n-1]];

        return ans;
    }
};