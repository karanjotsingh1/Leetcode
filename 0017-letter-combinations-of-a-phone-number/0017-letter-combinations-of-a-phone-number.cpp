// Approach
// 1. Har digit de corresponding characters ik mapping ch store karaange.
// 2. Backtracking use karke saare possible combinations generate karaange.
// 3. Har recursive call ch current digit de saare letters try karaange.
// 4. Ik character current string ch add karaange.
// 5. Next digit lai recursion call karaange.
// 6. Recursive call to baad current character remove karaange
//    (Backtracking).
// 7. Jadon current string di length digits di length de equal ho jaave,
//    ik valid combination mil gayi.
//    Usnu answer ch store karaange.
// 8. Je input string empty hove,
//    ta empty answer return karaange.

class Solution
{
public:
    void combinations(string& digits,
                      int idx,
                      unordered_map<char,string>& mp,
                      string& current,
                      vector<string>& ans)
    {
        if(idx==digits.size())
        {
            ans.push_back(current);
            return;
        }

        string letters=mp[digits[idx]];

        for(int i=0;i<letters.size();i++)
        {
            current.push_back(letters[i]);

            combinations(digits,idx+1,mp,current,ans);

            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;

        if(digits.empty())
        {
            return ans;
        }

        unordered_map<char,string> mp;

        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";

        string current;

        combinations(digits,0,mp,current,ans);

        return ans;
    }
};