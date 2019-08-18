#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> result(2, -1);
        const size_t numsSize = nums.size();
        for (size_t i = 0; i < numsSize; i++)
        {
            if (nums[i] == target)
            {
                result[0] = i;
                result[1] = i;
                for (size_t j = i + 1; j < numsSize; j++)
                {
                    if (nums[j] == target)
                    {
                        result[1] = j;
                    }
                }
                break;
            }
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums({5, 7, 7, 8, 8, 10});
    Solution so;
    auto result = so.searchRange(nums, 8);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
