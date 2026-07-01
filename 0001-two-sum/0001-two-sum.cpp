// Approach
// 1. Pehlaa aapaa ik map bnaavaange jo value de naal usda index store kru ga.
// 2. Hun array nu left to right traverse kraange.
// 3. Har element lai target chon current value subtract krke complement(left_part) kadd laavaange.
// 4. Je complement pehlaa hi map ch present aa,
//    matlab pair mil gya te dono indices return kr devaange.
// 5. Je complement nhi milya,
//    ta current element te usda index map ch store kr devaange
//    taaki future ch lookup fast ho sake.
// 6. Question guarantee krda aa ki ik solution hamesha houga.

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums,int target)
    {
        map<int,int>m;
        vector<int>ans;

        for(int i=0;i<nums.size();i++)
        {
            int left_part=target-nums[i];

            // Check if required complement already exists
            if(m.find(left_part)!=m.end())
            {
                ans.push_back(m[left_part]);
                ans.push_back(i);

                return ans;
            }

            // Store current value with its index
            m[nums[i]]=i;
        }

        return ans;
    }
};