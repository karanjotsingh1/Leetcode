class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert({nums[i]});
        }

        int idx=1;
        int num=k;
        while(true)
        {
            if(s.find(num)==s.end())
            {
                return num;
            }
            idx+=1;
            num=k*idx;
        }
        return k;
    }
};