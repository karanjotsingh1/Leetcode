// Approach
// 1. Binary Search use kraange.
// 2. Har step te arr[mid] nu arr[mid+1] naal compare kraange.
// 3. Je arr[mid]<arr[mid+1],
//    ta asi increasing slope te haan,
//    is karke peak right side hovegi.
// 4. Je arr[mid]>arr[mid+1],
//    ta asi decreasing slope te haan,
//    is karke peak mid ya left side hovegi.
// 5. Jadon left==right ho jaave,
//    ohi peak index hovega.

class Solution
{
public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        int left=0;
        int right=arr.size()-1;

        while(left<right)
        {
            int mid=left+(right-left)/2;

            if(arr[mid]<arr[mid+1])
            {
                left=mid+1;
            }
            else
            {
                right=mid;
            }
        }

        return left;
    }
};