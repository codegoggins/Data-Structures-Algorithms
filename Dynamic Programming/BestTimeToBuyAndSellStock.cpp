#include<bits/stdc++.h>
using namespace std;

// PROBLEM LINK :
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


// BRUTE FORCE APPROACH

// We can see that the max difference between the elements matters, we need to make sure that we buy before we sell so j is always greater that i

int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        for(int i=0;i<prices.size();i++){
            for(int j=i+1;j<prices.size();j++){
                
                int profit = prices[j] - prices[i];
                max_profit = max(max_profit,profit);
            }
        }
        return max_profit;
}

/*

TIME COMPLEXITY OF THE ABOVE CODE

The time complexity of this code is O(n^2), where n is the size of the input vector prices.

The reason for this is because the code uses a nested loop to compare all possible pairs of prices in the vector. The outer loop runs n times, where n is the size of the input vector, and the inner loop runs n-i times, where i is the current index of the outer loop. Therefore, the total number of iterations of the inner loop is the sum of (n-i) for i = 0 to n-1, which is equal to (n^2 + n)/2. This gives us a time complexity of O(n^2).

As the input size grows, the time taken by this algorithm increases quadratically. Therefore, for large input sizes, this algorithm may not be very efficient, and we may need to use more optimized algorithms like dynamic programming to solve the problem in a faster time complexity.

SPACE COMPLEXITY

The space complexity of this program is O(1) or constant space complexity, because the amount of memory used does not depend on the size of the input vector prices.

The program uses two variables, max_profit and profit, to keep track of the maximum profit and the current profit, respectively. It also uses two loop counters, i and j, to iterate through the vector prices.

Regardless of the size of prices, the program only uses a fixed amount of memory for these variables, so its space complexity is constant. Therefore, the program does not have any memory limitations and can handle inputs of any size.

*/