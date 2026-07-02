class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();

        int i=0;
        int j=n-1;
        while(i<n && s[i]==' ')
        {
            i++;
        }
        while(j>=0 && s[j]==' ')
        {
            j--;
        }

        
        reverse(s.begin(),s.end());
        s=s+" ";
        n=s.size();

        string ans;
        string substring="";
        
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ' && substring.size()!=0)
            {
                reverse(substring.begin(),substring.end());
                ans+=substring+" ";
                substring ="";
            }

            if(s[i]!=' ')
            {
                substring+=s[i];
            }

            
        }
        ans.resize(ans.size()-1);
        return ans;

    }
};