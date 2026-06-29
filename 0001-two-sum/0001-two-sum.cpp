#include<map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int, int> m; // value -> index
        vector<int>ans;
        for (int i=0;i<nums.size();i++) {
            int left_part=target-nums[i];// left number kdd lo 
            if (m.find(left_part) != m.end())// if already present in left side of array
             {
                ans.push_back(m[left_part]);
                ans.push_back(i);
                
                return ans; // found the pair
            }
            m[nums[i]] = i;// insert this pair also in hash map 

        }
        return ans; // no pair found
    }
};
