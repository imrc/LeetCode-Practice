/*

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
*/
int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();


        vector<int> last_was_buy(len+1,0); //cooldown days may be or may not be there after buy \\but no sell happened // including this day
        vector<int> last_was_sell(len+1,0); //cooldown days may be or may not be there after sell \\but no buy happend //including this day


        last_was_buy[1] = - prices[0]; // '-' indicates buy at that price
                                        //similarly '+' indicates sell at that price

        // '1' indexing followed. 'i' index means ith day {no zeroth day}
        for (int i = 2; i <= len; i++)
        {
            //max of (already holding stock{so cant buy}, buying stock now
            last_was_buy[i]  = max (last_was_buy[i-1], last_was_sell[i-1] - prices[i-1]) ;

           //max of (cooldone this day without selling, selling the stock holdnig)
            last_was_sell[i] = max (last_was_sell[i-1], last_was_buy[i-1] + prices[i-1]-fee);
        }

        return last_was_sell[len];
    }
