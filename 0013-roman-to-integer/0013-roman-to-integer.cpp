class Solution {
public:
    int romanToInt(string s) {
        map<char,int>m;
        m.insert({'I',1});
        m.insert({'V',5});
        m.insert({'X',10});
        m.insert({'L',50});
        m.insert({'C',100});
        m.insert({'D',500});
        m.insert({'M',1000});

        int ans=0;
        int n=s.size();

        for(int i=0;i<n-1;i++)
        {
            char ch=s[i];
            char ch1=s[i+1];
            if(m[ch]<m[ch1])
            {
                ans-=m[ch];
            }
            else
            {
                ans+=m[ch];
            }
        }
        ans+=m[s[n-1]];
        return ans;
        
    }
};