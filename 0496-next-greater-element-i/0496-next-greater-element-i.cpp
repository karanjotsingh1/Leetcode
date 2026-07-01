#include <map>
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int nn=nums1.size();
        int n=nums2.size();

        vector<int>ans(nn);
        map<int,int>m;
        stack<int>st;
        st.push(0);
        for(int i=1;i<n;i++)
        {
            while(st.empty()==false && nums2[i]>nums2[st.top()])
            {
                m[nums2[st.top()]]=nums2[i];
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<nn;i++)
        {
            if(m.find(nums1[i])==m.end())
                ans[i]=-1;
            else
                ans[i]=m[nums1[i]];
        }
        return ans;
    }
};