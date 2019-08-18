#include "prettyprint.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        size_t numsSize = nums.size();
        if (numsSize == 0)
        {
            return 0;
        }
        if (numsSize == 1)
        {
            return nums.front();
        }
        int total1 = 0, total2 = nums.front();
        for (size_t i = 1; i < numsSize; i++)
        {
            int curr1 = max(total1, total2), curr2 = total1 + nums[i];
            total1 = curr1;
            total2 = curr2;
        }
        return max(total1, total2);
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums({2, 1, 1, 2});
    cout << Solution().rob(nums) << endl;
    return 0;
}
