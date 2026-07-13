class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();

        if(n==1)
            return false;

        map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]+=1;
        }

        for(int i=0;i<n;i++)
        {
            if(m[nums[i]]>=2)
                return true;
        }
        return false;
        
    }
};