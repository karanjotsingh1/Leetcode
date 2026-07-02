// Approach
// 1. Pehlaa array nu sort kraange taaki first lexicographical permutation ton start hove.
// 2. Original sorted permutation nu answer ch store kraange.
// 3. Hun total permutations n! hundiyan ne,
//    ona vaar next permutation generate kraange.
// 4. Next permutation lai:
//    - Pivot labhaange.
//    - Pivot ton vadda first element right side ton labhaange.
//    - Dono nu swap kraange.
//    - Pivot de right wale part nu reverse kraange.
// 5. Har navi permutation nu answer ch add krde jaavaange.
// 6. Last ch saari permutations return kr devaange.

class Solution
{
public:
    vector<int> find_permutation(vector<int>arr,int n)
    {
        int pivot=-1;

        // Find the pivot
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]<arr[i+1])
            {
                pivot=i;
                break;
            }
        }

        if(pivot==-1)
        {
            reverse(arr.begin(),arr.end());
            return arr;
        }

        // Find the next greater element from the right
        for(int i=n-1;i>pivot;i--)
        {
            if(arr[i]>arr[pivot])
            {
                swap(arr[i],arr[pivot]);
                break;
            }
        }

        // Reverse the suffix
        reverse(arr.begin()+pivot+1,arr.end());

        return arr;
    }

    int fact(int n)
    {
        int result=1;

        for(int i=2;i<=n;i++)
        {
            result*=i;
        }

        return result;
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());

        int n=nums.size();
        int total=fact(n);

        vector<vector<int>>ans;
        vector<int>permutation=nums;

        ans.push_back(permutation);

        for(int i=1;i<total;i++)
        {
            permutation=find_permutation(permutation,n);
            ans.push_back(permutation);
        }

        return ans;
    }
};