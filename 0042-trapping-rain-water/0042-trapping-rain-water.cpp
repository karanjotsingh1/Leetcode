// Approach
// 1. Har index lai left side da maximum height calculate karaange.
// 2. Har index lai right side da maximum height calculate karaange.
// 3. Har index te water level
//    min(leftMax,rightMax) hovega.
// 4. Je water level current height ton vadda hove,
//    ta difference answer ch add karaange.
// 5. Saare indices traverse karan to baad
//    total trapped water return karaange.

class Solution
{
public:
    int trap(vector<int>& height)
    {
        int n=height.size();

        if(n==0)
        {
            return 0;
        }

        vector<int>leftMax(n);
        vector<int>rightMax(n);

        leftMax[0]=height[0];

        for(int i=1;i<n;i++)
        {
            leftMax[i]=max(leftMax[i-1],height[i]);
        }

        rightMax[n-1]=height[n-1];

        for(int i=n-2;i>=0;i--)
        {
            rightMax[i]=max(rightMax[i+1],height[i]);
        }

        int ans=0;

        for(int i=0;i<n;i++)
        {
            ans+=min(leftMax[i],rightMax[i])-height[i];
        }

        return ans;
    }
};