// Approach
// 1. Pehlaa answer nu "1" naal initialize kraange,
//    kyunki first term hamesha "1" hundi aa.
// 2. Hun n-1 vaar current string di next sequence generate kraange.
// 3. Ik helper function use kraange jo current string nu read kru ga.
// 4. Har consecutive same character di count calculate kraange.
// 5. Count te character nu answer string ch add kraange.
// 6. Navi string next iteration lai current answer ban jaegi.
// 7. Last ch nth sequence return kr devaange.

class Solution
{
public:
    string alphabet(string s)
    {
        int n=s.size();
        string ans="";

        for(int i=0;i<n;i++)
        {
            char ele=s[i];
            int count=1;

            while(i+1<n&&s[i]==s[i+1])
            {
                count++;
                i++;
            }

            ans+=to_string(count);
            ans+=ele;
        }

        return ans;
    }

    string countAndSay(int n)
    {
        if(n==1)
        {
            return "1";
        }

        string ans="1";

        for(int i=2;i<=n;i++)
        {
            ans=alphabet(ans);
        }

        return ans;
    }
};