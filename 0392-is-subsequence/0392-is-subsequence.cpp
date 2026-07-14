class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int idx=0;
        int s_size=s.size();

        for(int i=0;i<t.size();i++)
        {
            if(idx==s_size)
                return true;

            if(idx<s_size && t[i]==s[idx])
            {
                idx++;
            }
        }

        if(idx==s_size)
            return true;
            
        return false;

    }
};