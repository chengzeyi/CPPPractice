#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        const size_t numsSize = nums.size();
        size_t lastPos = numsSize - 1;
        for (size_t i = lastPos; i < numsSize; i--)
        {
            if (i + nums[i] >= lastPos)
            {
                lastPos = i;
            }
        }
        return lastPos == 0;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums0({2, 3, 1, 1, 4}), nums1({3, 2, 1, 0, 4});
    Solution so;
    cout << so.canJump(nums0) << endl;
    cout << so.canJump(nums1) << endl;
    return 0;
}
