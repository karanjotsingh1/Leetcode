// Approach
// 1. Array nu sort karaange,
//    taaki duplicate elements ikathe aa jaan.
// 2. Har element lai do choices explore karaange.
//    (a) Current element nu include karaange.
//    (b) Current element nu exclude karaange.
// 3. Je target 0 ho jaave,
//    matlab ik valid combination mil gayi.
//    Current combination nu answer ch store karaange.
// 4. Je target negative ho jaave
//    ya index array ton bahar chala jaave,
//    ta recursion stop kar devaange.
// 5. Include waali call ch
//    current element nu answer ch add karaange
//    te next index te recursion karaange,
//    kyunki ik element sirf ik vaar use ho sakda hai.
// 6. Backtracking karke
//    current element remove karaange.
// 7. Exclude waali call ch
//    current element de saare duplicates skip karaange,
//    taaki duplicate combinations na aun.
// 8. Is tarah saare unique valid combinations generate ho jaan ge.

class Solution
{
public:
    void combinations(vector<int>& candidates,int target,int idx,vector<int>& combo,vector<vector<int>>& ans)
    {
        // Valid combination found
        if(target==0)
        {
            ans.push_back(combo);
            return;
        }

        // Invalid case
        if(idx>=candidates.size() || target<0)
        {
            return;
        }

        // Include current element
        combo.push_back(candidates[idx]);

        combinations(candidates,target-candidates[idx],idx+1,combo,ans);

        combo.pop_back();

        // Skip duplicates while excluding
        while(idx+1<candidates.size() &&candidates[idx]==candidates[idx+1])
        {
            idx++;
        }

        // Exclude current element
        combinations(candidates,target,idx+1,combo,ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,int target)
    {
        sort(candidates.begin(),candidates.end());

        vector<vector<int>> ans;
        vector<int> combo;

        combinations(candidates,target,0,combo,ans);

        return ans;
    }
};