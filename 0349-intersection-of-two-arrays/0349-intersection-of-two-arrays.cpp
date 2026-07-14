// Approach
// 1. Pehla dono arrays nu sort karaange.
// 2. Do pointers (i te j) use karaange,
//    jo nums1 te nums2 traverse karange.
// 3. Je dono elements equal hon,
//    ta check karaange
//    ki answer ch pehla ton exist karde ne ya nahi.
// 4. Je element pehla add nahi hoya,
//    ta answer ch add karaange
//    te set ch insert karaange.
// 5. Dono pointers nu agge move karaange.
// 6. Je nums1 da element chhota hove,
//    ta i nu agge move karaange.
// 7. Je nums2 da element chhota hove,
//    ta j nu agge move karaange.
// 8. Traversal complete hon to baad
//    unique common elements return karaange.

class Solution
{
public:
    vector<int> intersection(vector<int>& nums1,vector<int>& nums2)
    {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int n=nums1.size();
        int m=nums2.size();

        int i=0;
        int j=0;

        set<int> visited;

        vector<int> answer;

        while(i<n && j<m)
        {
            if(nums1[i]==nums2[j])
            {
                if(visited.find(nums1[i])==visited.end())
                {
                    visited.insert(nums1[i]);

                    answer.push_back(nums1[i]);
                }

                i++;
                j++;
            }
            else if(nums1[i]<nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        return answer;
    }
};