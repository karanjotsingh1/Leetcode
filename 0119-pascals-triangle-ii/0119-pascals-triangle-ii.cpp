// Approach
// 1. First row [1] ton start karaange.
// 2. Previous row nu store karan lai ik vector maintain karaange.
// 3. Har navi row di starting te 1 add karaange.
// 4. Previous row de adjacent elements da sum
//    current row ch add karaange.
// 5. Current row de end te vi 1 add karaange.
// 6. Current row nu previous row bana ke
//    aggli iteration lai use karaange.
// 7. Jadon required row ban jaave,
//    usnu answer vich return karaange.

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> prev;

        prev.push_back(1);

        if(rowIndex==0)
        {
            return prev;
        }

        vector<int> ans;

        for(int i=0;i<rowIndex;i++)
        {
            ans.clear();

            ans.push_back(1);

            for(int j=1;j<prev.size();j++)
            {
                ans.push_back(prev[j-1]+prev[j]);
            }

            ans.push_back(1);

            prev=ans;
        }

        return ans;
    }
};