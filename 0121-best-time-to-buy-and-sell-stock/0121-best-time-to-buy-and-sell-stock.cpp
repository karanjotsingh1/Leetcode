// Approach
// 1. Ik variable maintain karaange
//    jo sab ton sasti buying day (best_buy) nu store karega.
// 2. Array nu left to right traverse karaange.
// 3. Je current price best_buy ton chhoti hove,
//    ta best_buy update karaange.
// 4. Nahi ta current day te sell karan da profit calculate karaange.
// 5. Maximum profit nu continuously update karaange.
// 6. Traversal complete hon to baad
//    maximum profit return karaange.
// 7. Je koi profitable transaction possible na hove,
//    ta answer 0 hi rahega.

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int n=prices.size();

        if(n==1)
        {
            return 0;
        }

        int best_buy=0;
        int max_profit=0;

        for(int i=1;i<n;i++)
        {
            if(prices[i]<prices[best_buy])
            {
                best_buy=i;
            }
            else
            {
                max_profit=max(max_profit,prices[i]-prices[best_buy]);
            }
        }

        return max_profit;
    }
};