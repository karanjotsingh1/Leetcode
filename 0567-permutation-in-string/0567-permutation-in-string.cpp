class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(),s1.end());

        int n=s1.size();
        
        if(n>s2.size())
            return false;

        for(int i=0;i<=s2.size()-n;i++)
        {
            string str=s2.substr(i,n);
            sort(str.begin(),str.end());
            if(str==s1)
                return true;

        }
        return false;
    }
};