// Approach
// 1. Ik unordered_map use karaange,
//    jithe key = sorted string
//    te value = answer vector da index hovega.
// 2. Har string nu traverse karaange.
// 3. Current string di ik copy bana ke
//    usnu sort karaange.
// 4. Sorted string saare anagrams lai
//    same hovegi,
//    is karke eh map di key ban jaavegi.
// 5. Je sorted string pehla map ch exist kardi hove,
//    ta original string nu
//    us group ch add karaange.
// 6. Je sorted string pehli vaar mili hove,
//    ta answer ch nava group banaavaange
//    te map ch us group da index store karaange.
// 7. Saari strings process hon to baad
//    answer return karaange.

class Solution
{
public:
    void isAnagram(vector<string>& strs,
                   unordered_map<string,int>& m,
                   vector<vector<string>>& ans)
    {
        int n=strs.size();

        for(int i=0;i<n;i++)
        {
            string s1=strs[i];

            // Form the key
            sort(s1.begin(),s1.end());

            if(m.find(s1)!=m.end())
            {
                ans[m[s1]].push_back(strs[i]);
            }
            else
            {
                ans.push_back({strs[i]});

                m[s1]=ans.size()-1;
            }
        }
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> ans;

        if(strs.size()==0)
        {
            return ans;
        }

        unordered_map<string,int> m;

        isAnagram(strs,m,ans);

        return ans;
    }
};