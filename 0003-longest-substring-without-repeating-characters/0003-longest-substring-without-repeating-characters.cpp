// Approach
// 1. Sliding Window use karaange.
// 2. Do pointers maintain karaange:
//    left te right.
// 3. Ik unordered_set use karaange
//    current window de unique characters store karan lai.
// 4. Right pointer nu move karke
//    window expand karaange.
// 5. Je current character pehla hi window ch present hove,
//    ta left pointer move karke
//    duplicate character remove karaange,
//    jad tak duplicate remove na ho jaave.
// 6. Duplicate remove hon to baad
//    current character set ch insert karaange.
// 7. Har step te current window di length calculate karke
//    maximum length update karaange.
// 8. Traversal complete hon to baad
//    maximum length return karaange.

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char>st;

        int left=0;
        int max_length=0;

        for(int right=0;right<s.size();right++)
        {
            while(st.find(s[right])!=st.end())
            {
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);

            max_length=max(max_length,right-left+1);
        }

        return max_length;
    }
};