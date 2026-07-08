// Approach
// 1. Har element lai do choices hundiyaan ne.
//    Ya ta us element nu subset ch include karaange,
//    ya exclude karaange.
// 2. Recursion di help naal eh dono choices har index te explore karaange.
// 3. Je index array de end tak pahunch jaave,
//    ta current subset nu answer ch store kar devaange.
// 4. Pehla current element nu include karke recursive call karaange.
// 5. Fir backtracking karke element remove karaange.
// 6. Us to baad current element nu exclude karke recursive call karaange.
// 7. Is tarah saare possible subsets generate ho jaan ge.

class Solution
{
public:
    void calculate_subsets(vector<int>& nums,int idx,vector<int>& subset,vector<vector<int>>& all_subsets,int& n)
    {
        if(idx>=n)
        {
            all_subsets.push_back(subset);
            return;
        }

        // Include current element
        subset.push_back(nums[idx]);

        calculate_subsets(nums,idx+1,subset,all_subsets,n);

        subset.pop_back();

        // Exclude current element
        calculate_subsets(nums,idx+1,subset,all_subsets,n);
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<int>subset;
        vector<vector<int>>all_subsets;

        int n=nums.size();

        calculate_subsets(nums,0,subset,all_subsets,n);

        return all_subsets;
    }
};