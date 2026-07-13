class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();

        int left=0;
        int ryt=n-1;

        int maxi=0;

        while(left<ryt)
        {
            int horizontal=ryt-left;
            int vertical=min(height[left],height[ryt]);
            maxi=max(maxi,horizontal*vertical);

            if(height[left] < height[ryt])
            {
                left++;
            }
            else if(height[left] > height[ryt])
            {
                ryt--;
            }
            else
            {
                left++;
                ryt--;
            }
        }
        return maxi;
    }
};