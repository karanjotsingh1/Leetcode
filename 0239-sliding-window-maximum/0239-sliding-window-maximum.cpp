class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n=nums.size();

        vector<int>ans;

        deque<int>q;

        // First window
        for(int i=0;i<k;i++)
        {
            while(q.empty()==false && nums[q.back()]<nums[i])
            {
                q.pop_back();
            }

            q.push_back(i);
        }

        ans.push_back(nums[q.front()]);

        // Remaining windows
        for(int i=k;i<n;i++)
        {
            // Remove elements outside the window
            while(q.empty()==false && q.front()<=i-k)
            {
                q.pop_front();
            }

            // Remove smaller elements
            while(q.empty()==false && nums[q.back()]<nums[i])
            {
                q.pop_back();
            }

            q.push_back(i);

            ans.push_back(nums[q.front()]);
        }

        return ans;
    }
};