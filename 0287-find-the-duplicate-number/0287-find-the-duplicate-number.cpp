// Approach
// 1. Pehlaa aapaa array nu linked list vangu treat kraange.
//    Har index ik node aa te nums[i] next node da address dassda aa.
// 2. Duplicate number karke linked list ch cycle ban jaandi aa.
// 3. Hun slow te fast pointer(Floyd Cycle Detection) use kraange.
//    Slow ik step chalega te fast do steps.
// 4. Jadon slow te fast mil jaan, matlab cycle de andar aa gaye.
// 5. Hun ik pointer start(index 0) te rakhange te dujja meeting point te.
// 6. Dono ik ik step chalange.
//    Jithe dono milange, ohi duplicate number houga.
// 7. Koi array modify nhi hovegi te extra space vi use nhi hovegi.

class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        int slow=nums[0];
        int fast=nums[0];

        // Find the meeting point inside the cycle
        do
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);

        int ptr1=nums[0];
        int ptr2=slow;

        // Find the entrance of the cycle
        while(ptr1!=ptr2)
        {
            ptr1=nums[ptr1];
            ptr2=nums[ptr2];
        }

        return ptr1;
    }
};