class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int n=prices.size();

        if(n==1)
            return 0;

        int best_buy=0;

        for(int i=1;i<n;i++)
        {
            if(prices[i]<prices[best_buy])
            {
                best_buy=i;
            }
            else
            {
                maxi=max(maxi,prices[i]-prices[best_buy]);
            }
        }
        return maxi;
    }
};