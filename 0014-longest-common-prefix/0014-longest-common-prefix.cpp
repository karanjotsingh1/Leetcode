// Approach
// 1. Pehlaa first do strings da common prefix find kraange.
// 2. Hun remaining strings nu ik ik karke compare kraange.
// 3. Je current string prefix naal start hundi aa,
//    ta agge move kr jaavaange.
// 4. Nahi ta current string te current prefix da common part find kraange.
// 5. Prefix nu update kr devaange.
// 6. Je prefix empty ho jaave,
//    ta sidha empty string return kr devaange.
// 7. Last ch final common prefix return kr devaange.

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int n=strs.size();

        if(n==1)
        {
            return strs[0];
        }

        int idx=0;
        string prefix="";

        while(idx<strs[0].size()&&idx<strs[1].size()&&strs[0][idx]==strs[1][idx])
        {
            prefix+=strs[0][idx];
            idx++;
        }

        for(int i=2;i<n;i++)
        {
            string str=strs[i];

            if(str.find(prefix)==0)
            {
                continue;
            }

            idx=0;
            string new_prefix="";

            while(idx<str.size()&&idx<prefix.size()&&str[idx]==prefix[idx])
            {
                new_prefix+=prefix[idx];
                idx++;
            }

            prefix=new_prefix;

            if(prefix.empty())
            {
                return "";
            }
        }

        return prefix;
    }
};