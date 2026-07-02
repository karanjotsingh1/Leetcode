class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();

        if(n==1)
            return strs[0];

        int idx=0;
        string prefix="";
        while(idx<strs[0].size() && idx<strs[1].size() && strs[0][idx]==strs[1][idx])
        {
            prefix+=strs[1][idx];
            idx++;
        }

        for(int i=2;i<n;i++)
        {
            string str=strs[i];
            if(str.find(prefix)==0)
            {
                continue;
            }
            else
            {
                int idx=0;
                string new_prefix="";
                while(idx<str.size() && str[idx]==prefix[idx])
                {
                    new_prefix+=prefix[idx];
                    idx++;
                }
                prefix=new_prefix;
            }
        }
        return prefix;
    }
};