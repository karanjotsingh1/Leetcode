// Approach
// 1. Do pointers use karaange:
//    ptr1 nums1 de valid elements de end te,
//    ptr2 nums2 de end te.
// 2. Ik third pointer idx
//    nums1 de last index te rakhaange.
// 3. Dono arrays de last elements compare karaange.
// 4. Jeda element vadda hove,
//    usnu nums1[idx] te place karaange.
// 5. Corresponding pointer te idx nu decrease karaange.
// 6. Jadon kise ik array de elements khatam ho jaan,
//    ta nums2 de remaining elements nums1 ch copy karaange.
// 7. Je nums1 de elements bach jaan,
//    unha nu move karan di zaroorat nahi,
//    kyunki oh pehla hi correct position te ne.

class Solution
{
public:
    void merge(vector<int>& nums1,int m,vector<int>& nums2,int n)
    {
        int ptr1=m-1;
        int ptr2=n-1;

        int idx=m+n-1;

        while(ptr1>=0 && ptr2>=0)
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

        while(ptr2>=0)
        {
            nums1[idx]=nums2[ptr2];
            ptr2--;
            idx--;
        }
    }
};