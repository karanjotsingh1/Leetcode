class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int i=n-1;
        while(s[i]==' ')// loop to remove spaces from end
        {
            i--;
        }
        int count=0;
        for(int ii=i;ii>=0;ii--)
        {
            if(s[ii]==' ')
                break;
            count++;
        }
        return count;
    }
};