#include "prettyprint.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
  private:
    void reverse(vector<int> &nums, size_t l, size_t r)
    {
        while (l < r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }

  public:
    void rotate(vector<int> &nums, int k)
    {
        size_t numsSize = nums.size(), km = k % numsSize;
        if (km == 0)
        {
            return;
        }
        reverse(nums, 0, numsSize - 1);
        reverse(nums, km, numsSize - 1);
        reverse(nums, 0, km - 1);
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums({1, 2, 3, 4, 5, 6, 7});
    Solution().rotate(nums, 3);
    cout << nums << endl;
    return 0;
}
