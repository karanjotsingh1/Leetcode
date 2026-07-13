// Approach
// 1. Do pointers use karaange:
//    left array de starting te
//    te ryt array de ending te.
// 2. Har step te container di width calculate karaange.
//    Width = ryt-left.
// 3. Container di height
//    left te ryt di minimum height hovegi.
// 4. Area = width × minimum height calculate karaange.
// 5. Maximum area (maxi) update karaange.
// 6. Jis side di height chhoti hove,
//    us pointer nu move karaange,
//    kyunki area nu improve karan da chance
//    sirf chhoti height nu increase karan naal hunda hai.
// 7. Je dono heights equal hon,
//    ta kise vi ik pointer nu move kar sakde haan.
// 8. Jadon left te ryt mil jaan,
//    traversal complete ho jaavegi.
// 9. Maximum area return karaange.

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int n=height.size();

        int left=0;
        int ryt=n-1;

        int maxi=0;

        while(left<ryt)
        {
            int horizontal=ryt-left;

            int vertical=min(height[left],height[ryt]);

            maxi=max(maxi,horizontal*vertical);

            if(height[left]<height[ryt])
            {
                left++;
            }
            else if(height[left]>height[ryt])
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