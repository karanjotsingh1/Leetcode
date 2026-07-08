class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ii=1;
        
        int n=nums.size();
        set<int>s;

        for(int i=0;i<n;i++)
        {

            while(s.find(ii)!=s.end())
            {
                s.erase(ii);
                ii+=1;
                
            }
            if(nums[i]==ii)
            {
                ii+=1;
            }
            else
            {
                s.insert(nums[i]);
            }

            

        }
        while(s.find(ii)!=s.end())
        {
            ii+=1;
        }

        return ii;
    }
};