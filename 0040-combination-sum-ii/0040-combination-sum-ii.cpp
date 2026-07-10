// Approach
// 1. Candidates array nu sort karaange,
//    taaki duplicate elements ikathe aa jaan.
// 2. Har recursive call ch current index ton
//    candidates explore karaange.
// 3. Je target 0 ho jaave,
//    matlab ik valid combination mil gayi.
//    Current combination nu answer ch store karaange.
// 4. Je same recursive level te duplicate element aave,
//    ta usnu skip karaange
//    (i>idx && candidates[i]==candidates[i-1]).
// 5. Je current candidate target ton vadda hove,
//    ta break kar devaange,
//    kyunki sorted array ch agge saare elements vi vadde honge.
// 6. Current candidate nu include karaange.
// 7. Recursive call ch i+1 pass karaange,
//    kyunki har element sirf ik vaar use ho sakda hai.
// 8. Recursive call to baad current candidate remove karaange
//    (Backtracking).
// 9. Is tarah saare unique valid combinations generate ho jaan ge.

class Solution
{
public:
    void combination(vector<int>& candidates,int target,int idx,vector<vector<int>>& ans,vector<int>& ele)
    {
        // Valid combination found
        if(target==0)
        {
            ans.push_back(ele);
            return;
        }

        for(int i=idx;i<candidates.size();i++)
        {
            // Skip duplicate elements
            if(i>idx && candidates[i]==candidates[i-1])
            {
                continue;
            }

            // No need to continue further
            if(candidates[i]>target)
            {
                break;
            }

            // Include current candidate
            ele.push_back(candidates[i]);

            combination(candidates,target-candidates[i],i+1,ans,ele);

            // Backtrack
            ele.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,int target)
    {
        sort(candidates.begin(),candidates.end());

        vector<vector<int>> ans;
        vector<int> ele;

        combination(candidates,target,0,ans,ele);

        return ans;
    }
};