// Approach
// 1. Map use karaange,
//    taaki saare unique elements automatically sorted order ch aa jaan.
// 2. Har unique element nu initially map ch insert karaange.
// 3. Smallest element ton starting karke
//    har unique element nu increasing rank assign karaange.
// 4. Original array traverse karaange.
// 5. Har element nu usdi corresponding rank naal replace karaange.
// 6. Modified array return karaange.

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int>& arr)
    {
        map<int,int> mp;

        // Store unique elements
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]=1;
        }

        // Assign ranks
        int rank=1;

        for(auto it:mp)
        {
            mp[it.first]=rank;
            rank++;
        }

        // Replace elements with their ranks
        for(int i=0;i<arr.size();i++)
        {
            arr[i]=mp[arr[i]];
        }

        return arr;
    }
};