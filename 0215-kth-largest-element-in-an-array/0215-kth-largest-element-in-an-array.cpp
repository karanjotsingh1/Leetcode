class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
        }

        k=k-1;

        if(k==0)
            return pq.top();

        while(k--)
        {
            pq.pop();
        }
        return pq.top();
    }
};