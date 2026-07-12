// Approach
// 1. Do pointers use karaange:
//    ik array de starting te (left)
//    te ik ending te (right).
// 2. Har step te current container da area calculate karaange.
//    Area = min(height[left],height[right]) × (right-left).
// 3. Maximum area update karaange.
// 4. Jis side di height chhoti hove,
//    us pointer nu move karaange,
//    kyunki area nu improve karan da chance
//    sirf chhoti height nu increase karan naal hunda hai.
// 5. Je dono heights equal hon,
//    ta kise vi ik pointer nu move kar sakde haan.
// 6. Jadon left pointer right pointer nu meet kar jaave,
//    traversal complete ho jaavegi.
// 7. Maximum area return karaange.

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int n=height.size();

        int left=0;
        int right=n-1;

        int max_area=0;

        while(left<right)
        {
            int area=min(height[left],height[right])*(right-left);

            max_area=max(max_area,area);

            if(height[left]<height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return max_area;
    }
};