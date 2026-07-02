// Approach
// 1. Pehlaa check kraange je dono strings di length different aa,
//    ta anagram possible nhi, false return kr devaange.
// 2. Hun do frequency arrays bnaavaange,
//    ik s lai te ik t lai.
// 3. Dono strings traverse krke
//    har character di frequency count kraange.
// 4. Hun 26 characters di frequencies compare kraange.
// 5. Je kise vi character di frequency different hove,
//    ta false return kr devaange.
// 6. Je saari frequencies same hon,
//    ta strings anagram ne, true return kr devaange.

class Solution
{
public:
    bool isAnagram(string s,string t)
    {
        if(s.size()!=t.size())
        {
            return false;
        }

        vector<int>alpha1(26,0);
        vector<int>alpha2(26,0);

        for(int i=0;i<s.size();i++)
        {
            alpha1[s[i]-'a']++;
        }

        for(int i=0;i<t.size();i++)
        {
            alpha2[t[i]-'a']++;
        }

        for(int i=0;i<26;i++)
        {
            if(alpha1[i]!=alpha2[i])
            {
                return false;
            }
        }

        return true;
    }
};