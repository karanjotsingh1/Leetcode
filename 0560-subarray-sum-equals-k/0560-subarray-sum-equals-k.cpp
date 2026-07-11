class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();

        if(n==1 && nums[0]==k)
            return 1;

        if(n==1 && nums[0]!=k)
            return 0;
  
        unordered_map<int,int>m;
        m[0]=1;

        int prefix_sum=0;
        int count=0;

        for(int i=0;i<n;i++)
        {
            prefix_sum+=nums[i];
            int remaining=prefix_sum-k;
            count+=m[remaining];
            m[prefix_sum]+=1;
        }
        return count;
    }
};