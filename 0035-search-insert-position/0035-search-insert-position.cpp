// Approach
// 1. Binary Search use karaange.
// 2. Do pointers maintain karaange:
//    left te right.
// 3. Har iteration ch middle index calculate karaange.
// 4. Je middle element target de equal hove,
//    ta usda index return karaange.
// 5. Je middle element target ton chhota hove,
//    ta search right half ch karaange.
// 6. Je middle element target ton vadda hove,
//    ta search left half ch karaange.
// 7. Jadon loop khatam ho jaave,
//    left pointer insertion position nu point karega.
// 8. Left return karaange.

class Solution
{
public:
    int searchInsert(vector<int>& arr,int target)
    {
        int n=arr.size();

        int left=0;
        int right=n-1;

        while(left<=right)
        {
            int mid=left+(right-left)/2;

            if(arr[mid]==target)
            {
                return mid;
            }
            else if(arr[mid]<target)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }

        return left;
    }
};