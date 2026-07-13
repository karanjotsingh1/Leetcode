class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int ptr1=m-1;
        int ptr2=n-1;

        int idx=nums1.size()-1;

        while(ptr1>=0 && ptr2>=0)
        {
            if(nums1[ptr1]>nums2[ptr2])
            {
                nums1[idx]=nums1[ptr1];
                idx--;
                ptr1--;
            }
            else if(nums1[ptr1]<nums2[ptr2])
            {
                nums1[idx]=nums2[ptr2];
                idx--;
                ptr2--;
            }
            else
            {
                nums1[idx]=nums2[ptr2];
                idx--;
                ptr2--;

                nums1[idx]=nums1[ptr1];
                idx--;
                ptr1--;
            }
        }

        while(ptr2>=0)
        {
            nums1[idx]=nums2[ptr2];
            idx--;
            ptr2--;
        }
        return;
    }
};