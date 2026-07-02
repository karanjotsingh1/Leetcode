// Approach
// 1. Pehlaa poori string reverse kraange.
// 2. Hun ik ik character traverse kraange.
// 3. Har word temporary string ch store kraange.
// 4. Jadon space mile,
//    ta current word nu reverse krke answer ch add kraange.
// 5. Multiple spaces automatically ignore ho jaan ge,
//    kyunki substring empty hove ta add nhi kraange.
// 6. Last ch extra trailing space remove krke answer return kr devaange.

class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(),s.end());

        s.push_back(' ');

        string ans="";
        string substring="";

        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                if(substring.size()!=0)
                {
                    reverse(substring.begin(),substring.end());
                    ans+=substring+" ";
                    substring="";
                }
            }
            else
            {
                substring+=s[i];
            }
        }

        ans.pop_back();

        return ans;
    }
};