// Approach
// 1. Map di help naal har element di frequency count karaange.
// 2. Ik set banaavaange.
// 3. Har frequency nu set ch insert karaange.
// 4. Je kise frequency pehla hi set ch hove,
//    matlab do elements di occurrence same hai.
//    Is karke false return karaange.
// 5. Je saari frequencies unique hon,
//    ta true return karaange.

class Solution
{
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        map<int,int>freq;

        for(int x:arr)
        {
            freq[x]++;
        }

        set<int>st;

        for(auto it:freq)
        {
            if(st.find(it.second)!=st.end())
            {
                return false;
            }

            st.insert(it.second);
        }

        return true;
    }
};