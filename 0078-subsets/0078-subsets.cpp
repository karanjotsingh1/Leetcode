// Approach
// 1. Har element lai do choices hongiyan:
//    (a) Current element nu include karna.
//    (b) Current element nu exclude karna.
// 2. Include waali call ch
//    current element subset ch add karaange.
// 3. Next index lai recursion call karaange.
// 4. Recursive call ton baad
//    backtracking karke current element remove karaange.
// 5. Hun exclude waali call karaange,
//    jithe current element nu ignore karke
//    next index te move karaange.
// 6. Jadon index array di size de equal ho jaave,
//    current subset complete ho chukka hovega.
//    Usnu answer ch store karaange.
// 7. Is tarah saare possible subsets generate ho jaan ge.

class Solution
{
public:
    void subset_combination(vector<int>& nums,
                            int& n,
                            int idx,
                            vector<int>& subset,
                            vector<vector<int>>& subsets)
    {
        if(idx==n)
        {
            subsets.push_back(subset);
            return;
        }

        // Include current element
        subset.push_back(nums[idx]);

        subset_combination(nums,n,idx+1,subset,subsets);

        subset.pop_back();

        // Exclude current element
        subset_combination(nums,n,idx+1,subset,subsets);
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        int n=nums.size();

        vector<int> subset;
        vector<vector<int>> subsets;

        subset_combination(nums,n,0,subset,subsets);

        return subsets;
    }
};