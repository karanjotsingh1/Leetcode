// Approach
// 1. Har row lai ik string maintain karaange.
// 2. Current row te direction maintain karaange.
// 3. Starting ch first row ton start karaange.
// 4. Har character nu current row di string ch add karaange.
// 5. Je first row ya last row te pahunch jaaiye,
//    ta direction reverse kar devaange.
// 6. Direction de according
//    next row te move karaange.
// 7. Saare characters process karan to baad
//    saari rows nu concatenate karke
//    final answer return karaange.

class Solution
{
public:
    string convert(string s,int numRows)
    {
        if(numRows==1 || numRows>=s.size())
        {
            return s;
        }

        vector<string> rows(numRows);

        int currentRow=0;
        bool goingDown=false;

        for(char ch:s)
        {
            rows[currentRow]+=ch;

            if(currentRow==0 || currentRow==numRows-1)
            {
                goingDown=!goingDown;
            }

            if(goingDown)
            {
                currentRow++;
            }
            else
            {
                currentRow--;
            }
        }

        string ans="";

        for(int i=0;i<numRows;i++)
        {
            ans+=rows[i];
        }

        return ans;
    }
};