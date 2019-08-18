#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        const size_t days = prices.size();
        if (days <= 1)
        {
            return 0;
        }
        int lowest = prices[0], last = prices[0], totalMaxProfit = 0;
        for (size_t i = 1; i < days; i++)
        {
            const int price = prices[i];
            if (price < last)
            {
                totalMaxProfit += (last - lowest);
                lowest = price;
            }
            last = price;
        }
        return totalMaxProfit + last - lowest;
    }
};

int main(int argc, char *argv[])
{
    vector<int> prices({7, 1, 5, 3, 6, 4});
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}
