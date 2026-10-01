#include <iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for(int i = 0; i < prices.size(); i++) {

            if(prices[i] < minPrice) {
                minPrice = prices[i];
            }

            int profit = prices[i] - minPrice;
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};

#include <iostream>
using namespace std;

int main() {
    Solution sol;
    int n_prices;
    cin >> n_prices;
    vector<int> prices(n_prices);
    for(int i=0; i<n_prices; i++) cin >> prices[i];
    cout << sol.maxProfit(prices) << endl;
    return 0;
}
