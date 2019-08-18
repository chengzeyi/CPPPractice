#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    int findMin(vector<int> &nums)
    {
        size_t numsSize = nums.size();
        int rightMax = nums.back();
        if (numsSize == 1)
        {
            return rightMax;
        }
        size_t left = 0, right = numsSize - 1;
        while (left + 1 < right)
        {
            size_t mid = (left + right) / 2;
            int midNum = nums[mid];
            if (midNum > rightMax)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        return min(nums[left], nums[right]);
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums({4, 5, 6, 7, 0, 1, 2});
    cout << Solution().findMin(nums);
    return 0;
}
