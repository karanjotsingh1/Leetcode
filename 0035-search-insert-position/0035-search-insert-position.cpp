class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int n=arr.size();

        int left=0;
        int ryt=n-1;

        while(left<=ryt)
        {
            int mid=(left+((ryt-left)/2));
            
            if(arr[mid] < target)
            {
                left=mid+1;
            }
            else if(arr[mid] > target)
            {
                ryt=mid-1;
            }
            else
            {
                return mid;
            }
        }
        return left;
    }
};