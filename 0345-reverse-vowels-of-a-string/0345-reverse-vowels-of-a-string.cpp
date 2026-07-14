class Solution {
public:
    bool is_vowel(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
            return true;

        return false;
    }
    string reverseVowels(string s) {
        int n=s.size();

        int i=0;
        int j=n-1;

        while(i<j)
        {
            if(is_vowel(s[i]) && is_vowel(s[j]))
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }

            else
            {
                if(is_vowel(s[i])==false)
                {
                    i++;
                }
                if(is_vowel(s[j])==false)
                {
                    j--;
                }
            }
        }
        return s;
    }
};