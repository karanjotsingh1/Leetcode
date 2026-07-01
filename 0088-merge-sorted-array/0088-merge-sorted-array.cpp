// Approach
// 1. Pehlaa aapaa nums1 de last valid element te nums2 de last element to start kraange.
// 2. Ik hor pointer nums1 de bilkul last index te rakhange jithe final answer store houga.
// 3. Hun dovaan arrays de last elements compare kraange.
// 4. Jehda vadda houga, onu nums1 de end ch rakh ke corresponding pointer pichhe le aavaange.
// 5. Je nums2 de elements bach jaan, ona nu nums1 ch copy kr devaange.
// 6. Je nums1 de elements bach jaan, ona nu kujh krn di lod nhi,
//    kyunki oh already correct position te ne.

class Solution
{
public:
    void merge(vector<int>& nums1,int m,vector<int>& nums2,int n)
    {
        int ptr1=m-1;
        int ptr2=n-1;
        int idx=m+n-1;

        // Fill nums1 from the back
        while(ptr1>=0&&ptr2>=0)
        {
            if(nums1[ptr1]>nums2[ptr2])
            {
                nums1[idx]=nums1[ptr1];
                ptr1--;
            }
            else
            {
                nums1[idx]=nums2[ptr2];
                ptr2--;
            }

            idx--;
        }

        // Copy remaining elements of nums2
        while(ptr2>=0)
        {
            nums1[idx]=nums2[ptr2];
            ptr2--;
            idx--;
        }
    }
};