// Approach
// 1. Har candidate lai do choices hundiyaan ne.
//    (a) Current candidate nu include karaange.
//    (b) Current candidate nu skip karke next candidate te move karaange.
// 2. Je target 0 ho jaave,
//    matlab ik valid combination mil gayi.
//    Current combination nu answer ch store karaange.
// 3. Je target negative ho jaave,
//    ya saare candidates traverse ho jaan,
//    ta recursion stop kar devaange.
// 4. Include waali recursive call ch
//    same index use hovega,
//    kyunki ik candidate unlimited times use ho sakda hai.
// 5. Recursive call to baad current candidate remove karaange
//    (Backtracking).
// 6. Fir current candidate nu skip karke
//    next index ton recursion call karaange.
// 7. Is tarah saare possible valid combinations generate ho jaan ge.

class Solution
{
public:
    void combinations(vector<int>& candidates,int target,int n,vector<int>& combo,vector<vector<int>>& ans,int idx)
    {
        // Valid combination found
        if(target==0)
        {
            ans.push_back(combo);
            return;
        }

        // Invalid case
        if(idx>=n || target<0)
        {
            return;
        }

        // Include current candidate
        combo.push_back(candidates[idx]);

        combinations(candidates,target-candidates[idx],n,combo,ans,idx);

        // Backtrack
        combo.pop_back();

        // Exclude current candidate
        combinations(candidates,target,n,combo,ans,idx+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,int target)
    {
        vector<vector<int>> ans;
        vector<int> combo;

        combinations(candidates,target,candidates.size(),combo,ans,0);

        return ans;
    }
};