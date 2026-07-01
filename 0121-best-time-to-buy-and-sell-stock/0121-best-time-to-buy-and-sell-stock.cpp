// Approach
// 1. Pehlaa aapaa buyin_day rakhange jo minimum price wale din da index store kru ga.
// 2. Hun array nu left to right traverse kraange.
// 3. Je current price buyin_day wale price ton chhoti aa,
//    ta buyin_day update kr devaange kyunki sanu hor sasta stock mil gya.
// 4. Nahi ta current day te sell krke profit calculate kraange.
// 5. Har step te maximum profit update krde jaavaange.
// 6. Je kise vi transaction naal profit na bane,
//    ta profit 0 hi return houga.

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int n=prices.size();
        int buyin_day=0;
        int profit=0;

        for(int i=0;i<n;i++)
        {
            // Update the day having minimum buying price
            if(prices[i]<prices[buyin_day])
            {
                buyin_day=i;
            }
            else
            {
                // Calculate profit by selling today
                profit=max(profit,prices[i]-prices[buyin_day]);
            }
        }

        return profit;
    }
};