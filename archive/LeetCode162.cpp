#include "prettyprint.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
  private:
    int search(vector<int> &nums, size_t l, size_t r)
    {
        if (l == r)
        {
            return l;
        }
        size_t mid = (l + r) / 2;
        if (nums[mid] > nums[mid + 1])
        {
            return search(nums, l, mid);
        }
        else
        {
            return search(nums, mid + 1, r);
        }
    }

  public:
    int findPeakElement(vector<int> &nums)
    {
        return search(nums, 0, nums.size() - 1);
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums({1, 2, 1, 3, 5, 6, 4});
    cout << nums << endl;
    cout << Solution().findPeakElement(nums) << endl;
    return 0;
}
