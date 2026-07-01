// Approach
// 1. Pehlaa aapaa nums2 te Monotonic Stack use kraange.
// 2. Stack ch indices store honge jinna da next greater element hale nhi milya.
// 3. Je current element stack de top wale element ton vadda hove,
//    ta current element usda next greater houga.
//    Onu map ch store krke stack ton pop kr devaange.
// 4. Baad ch current index stack ch push kr devaange.
// 5. Hun nums1 traverse kraange.
// 6. Je element map ch present aa,
//    ta usda next greater answer ch store kr devaange.
//    Nahi ta -1 store kr devaange.

#include<map>
#include<stack>
#include<vector>

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1,vector<int>& nums2)
    {
        int nn=nums1.size();
        int n=nums2.size();

        vector<int>ans(nn);

        map<int,int>m;
        stack<int>st;

        st.push(0);

        for(int i=1;i<n;i++)
        {
            // Find next greater element for indices in the stack
            while(!st.empty()&&nums2[i]>nums2[st.top()])
            {
                m[nums2[st.top()]]=nums2[i];
                st.pop();
            }

            st.push(i);
        }

        // Build the answer for nums1
        for(int i=0;i<nn;i++)
        {
            if(m.find(nums1[i])!=m.end())
            {
                ans[i]=m[nums1[i]];
            }
            else
            {
                ans[i]=-1;
            }
        }

        return ans;
    }
};