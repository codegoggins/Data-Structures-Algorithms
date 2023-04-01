#include<bits/stdc++.h>
using namespace std;

// PROBLEM LINK :
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


// OPTIMIZED APPROACH

// As we traverse the array we will always keep the track of the smallest element to the left of the current element in the array
// We keep track of the difference between the current element and the smallest element to the left

int maxProfit(vector<int>& prices) {
        int max_profit = 0, minEl=prices[0];
        for(int i=1;i<prices.size();i++){
            int profit = prices[i] - minEl;
            max_profit = max(profit,max_profit);
            minEl = min(minEl,prices[i]);
        }
        return max_profit;
}

/*

TIME COMPLEXITY OF THE ABOVE CODE

The code has a single for-loop which iterates over the input vector 'prices' once, from the second element to the last element. The operations inside the loop take constant time. Therefore, the time complexity of this code is O(n), where n is the size of the input vector 'prices'.

SPACE COMPLEXITY

The code uses only a few constant-sized variables, such as 'max_profit' and 'minEl', which do not depend on the size of the input vector 'prices'. Therefore, the space complexity of this code is O(1), which is constant.

*/