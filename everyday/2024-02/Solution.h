#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    // 122. 买卖股票的最佳时机 II
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        std::stack<int> cur; // 当前买入
        cur.push(prices[0]);
        for(int i=1;i<prices.size();i++){
            int diff = prices[i]-prices[i-1];
            if(diff < 0){
                // 跌
                profit += prices[i-1]-cur.top();
                cur.pop();
                cur.push(prices[i]);
            }
        }
        // 检查是否有没卖的
        if(cur.size()!=0){
            profit += prices[prices.size()-1]-cur.top();
            cur.pop();
        }

        return profit;
    }
    // 买卖股票的最佳时机含冷冻期
    int maxProfit2(vector<int>& prices){
        // 动态规划
    }
};