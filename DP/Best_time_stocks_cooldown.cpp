
/*

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

*/


int maxProfit(vector<int>& prices) {

        int len = prices.size();

        ///intuition is from dietpepsi soln's botim's comment
        /*
        On any i-th day, we can buy, sell or cooldown

    buy[i]: The maximum profit can be made if the first i days end with buy or wait. E.g "buy, sell, buy" or "buy, cooldown, cooldown"

    sell[i]: The maximum profit can be made if the first i days end with sell or wait. E.g "buy, sell, buy, sell" or "buy, sell, cooldown, cooldown"
    price: prices[i - 1], which is the stock price of the i-th day

To calculate sell[i]:
                If we sell on the i-th day, the maximum profit is buy[i - 1] + price, because we have to buy before we can sell.
                If we cooldown on the i-th day, the maximum profit is same as sell[i - 1] since we did not do anything on the i-th day.
                So sell[i] is the larger one of (buy[i - 1] + price, sell[i - 1])

To calculate buy[i]:
                If we buy on the i-th day, the maximum profit is sell[i - 2] - price, because on the (i-1)th day we can only cooldown.
                If we cooldown on the i-th day, the maximum profit is same as buy[i - 1] since we did not do anything on the i-th day.
                So sell[i] is the larger one of (sell[i - 2] - price, buy[i - 1])
        */

        vector<int> last_was_buy(len+1,0); //cooldown days may be or may not be there after buy \\but no sell happened // including this day
        vector<int> last_was_sell(len+1,0); //cooldown days may be or may not be there after sell \\but no buy happend //including this day


        last_was_buy[1] = - prices[0]; // '-' indicates buy at that price
                                        //similarly '+' indicates sell at that price

        // '1' indexing followed. 'i' index means ith day {no zeroth day}
        for (int i = 2; i <= len; i++)
        {
            //max of (already holding stock{so cant buy}, buying stock now after 1 cooldown day
            last_was_buy[i]  = max (last_was_buy[i-1], last_was_sell[i-2] - prices[i-1]) ;

           //max of (cooldone this day without selling, selling the stock holdnig)
            last_was_sell[i] = max (last_was_sell[i-1], last_was_buy[i-1] + prices[i-1]);
        }

        return last_was_sell[len];

    }
