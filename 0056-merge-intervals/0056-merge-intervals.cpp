// 1. Pehla saare intervals nu starting point de basis te sort karaange.
// 2. First interval nu answer ch add karaange.
// 3. Har next interval lai current start <= last merged interval da end
//    → Overlap hai
//    → End nu max(end1, end2) karaange.
// 4. Je current start >last merged end
//    → Overlap nahi hai
//    → Current interval nu answer ch add karaange.
// 5. Finally answer return karaange.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==1)
            return intervals;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++)
        {
            int current_start=intervals[i][0];
            int current_end=intervals[i][1];
            int last_end=ans.back()[1];
            
            if(current_start<=last_end)
            {
                ans.back()[1]=max(last_end,current_end);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};