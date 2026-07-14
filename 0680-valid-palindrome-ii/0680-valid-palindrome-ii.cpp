// Approach
// 1. Do pointers (left te right)
//    string de dono ends ton start karaange.
// 2. Jadon tak characters equal hon,
//    dono pointers nu center wal move karaange.
// 3. Je kise position te mismatch mile,
//    ta do possibilities check karaange:
//    (a) Left character remove karke
//        remaining string palindrome hai ya nahi.
//    (b) Right character remove karke
//        remaining string palindrome hai ya nahi.
// 4. Je dono possibilities fail ho jaan,
//    ta false return karaange.
// 5. Je kise ik possibility ch
//    palindrome ban jaave,
//    ta true return karaange.
// 6. Je poori string bina mismatch de traverse ho jaave,
//    ta string already palindrome hai.
//    True return karaange.

class Solution
{
public:

    bool valid_palin(string s,int left,int right)
    {
        while(left<right)
        {
            if(s[left]!=s[right])
            {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    bool validPalindrome(string s)
    {
        int left=0;
        int right=s.size()-1;

        while(left<right)
        {
            if(s[left]==s[right])
            {
                left++;
                right--;
            }
            else
            {
                return valid_palin(s,left+1,right) ||
                       valid_palin(s,left,right-1);
            }
        }

        return true;
    }
};