// Approach
// 1. Pehla array nu sort karaange,
//    taaki duplicate elements ikathe aa jaan.
// 2. Har element lai do choices hongiyan:
//    (a) Current element nu include karna.
//    (b) Current element nu exclude karna.
// 3. Include waali call ch
//    current element nu subset ch add karaange
//    te next index te recursion karaange.
// 4. Recursive call ton baad
//    backtracking karke current element remove karaange.
// 5. Exclude karan ton pehla
//    current element de saare duplicates skip karaange.
// 6. Fer next different element ton
//    recursion continue karaange.
// 7. Jadon index array di size de equal ho jaave,
//    current subset nu answer ch store karaange.
// 8. Is tarah duplicate subsets generate nahi honge.

class Solution
{
public:
    void subsets_combination(vector<int>& nums,int n,int idx,vector<int>& subset,vector<vector<int>>& subsets)
    {
        if(idx==n)
        {
            subsets.push_back(subset);
            return;
        }

        // Include current element
        subset.push_back(nums[idx]);

        subsets_combination(nums,n,idx+1,subset,subsets);

        subset.pop_back();

        // Skip all duplicates before excluding
        while(idx+1<n && nums[idx]==nums[idx+1])
        {
            idx++;
        }

        // Exclude current element
        subsets_combination(nums,n,idx+1,subset,subsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());

        vector<vector<int>> subsets;
        vector<int> subset;

        subsets_combination(nums,nums.size(),0,subset,subsets);

        return subsets;
    }
};