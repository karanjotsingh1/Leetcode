// Approach
// 1. Pehlaa har index nu palindrome da center mann ke check kraange.
// 2. Do cases handle kraange:
//    - Odd length palindrome (center ik character)
//    - Even length palindrome (center do characters de vich)
// 3. Har center ton left te right expand kraange
//    jadon takk characters equal hunde ne.
// 4. Har expansion te palindrome di length compare kraange.
//    Je current palindrome vadda hove,
//    ta answer update kr devaange.
// 5. Saare possible centers check hon to baad,
//    answer ch longest palindromic substring mil jaegi.

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n=s.size();
        string ans="";

        for(int i=0;i<n;i++)
        {
            // Check odd length palindrome
            int left=i;
            int right=i;

            while(left>=0&&right<n&&s[left]==s[right])
            {
                if(right-left+1>ans.size())
                {
                    ans=s.substr(left,right-left+1);
                }

                left--;
                right++;
            }

            // Check even length palindrome
            left=i;
            right=i+1;

            while(left>=0&&right<n&&s[left]==s[right])
            {
                if(right-left+1>ans.size())
                {
                    ans=s.substr(left,right-left+1);
                }

                left--;
                right++;
            }
        }

        return ans;
    }
};