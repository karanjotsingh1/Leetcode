// Approach
// 1. Do pointers use karaange:
//    left starting te,
//    right ending te.
// 2. Do variables maintain karaange:
//    leftMax te rightMax.
// 3. Je left height right height ton chhoti ya equal hove,
//    ta left side process karaange.
// 4. Je current left height leftMax ton vaddi hove,
//    ta leftMax update karaange.
//    Nahi ta leftMax-height[left]
//    answer ch add karaange.
// 5. Je right height chhoti hove,
//    ta right side process karaange.
// 6. Je current right height rightMax ton vaddi hove,
//    ta rightMax update karaange.
//    Nahi ta rightMax-height[right]
//    answer ch add karaange.
// 7. Jadon left pointer right pointer nu cross kar jaave,
//    traversal complete ho jaavegi.
// 8. Total trapped water return karaange.

class Solution
{
public:
    int trap(vector<int>& height)
    {
        int n=height.size();

        int left=0;
        int right=n-1;

        int leftMax=0;
        int rightMax=0;

        int ans=0;

        while(left<right)
        {
            if(height[left]<=height[right])
            {
                if(height[left]>=leftMax)
                {
                    leftMax=height[left];
                }
                else
                {
                    ans+=leftMax-height[left];
                }

                left++;
            }
            else
            {
                if(height[right]>=rightMax)
                {
                    rightMax=height[right];
                }
                else
                {
                    ans+=rightMax-height[right];
                }

                right--;
            }
        }

        return ans;
    }
};