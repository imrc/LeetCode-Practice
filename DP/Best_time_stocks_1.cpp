

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

*/

int maxProfit(vector<int>& prices) {

        int buy_day  = 0;

        int max_profit = 0;

        for(int i = 1; i < prices.size(); i++)
        {
            int profit = 0;
            //calculate profit by selling this if possible
            if(prices[i] > prices[buy_day])
                profit = prices[i] - prices[buy_day];

            //updating buy_day
            else if(prices[buy_day] > prices[i] )
                buy_day = i;

            //maximizing profit
            max_profit = max (max_profit, profit);

        }

        return max_profit;

    }
