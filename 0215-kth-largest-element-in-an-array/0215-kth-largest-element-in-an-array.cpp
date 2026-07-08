// Approach
// 1. Min Heap (Priority Queue) of size k maintain kraange.
// 2. Array de har element nu heap ch push kraange.
// 3. Je heap da size k ton vadh ho jaave,
//    ta smallest element pop kar devaange.
// 4. Is tarah heap ch hamesha k largest elements hi rahange.
// 5. Traversal complete hon to baad,
//    heap da top kth largest element hovega.

class Solution
{
public:
    int findKthLargest(vector<int>& nums,int k)
    {
        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);

            if(pq.size()>k)
            {
                pq.pop();
            }
        }

        return pq.top();
    }
};