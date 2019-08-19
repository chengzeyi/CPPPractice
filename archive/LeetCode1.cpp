#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, size_t> numToIndex;
        const size_t numsSize = nums.size();
        for (size_t i = 0; i < numsSize; i++)
        {
            const int num = nums[i];
            const int another = target - num;
            const auto iter = numToIndex.find(another);
            if (iter == numToIndex.end())
            {
                numToIndex.emplace(num, i);
            }
            else
            {
                return vector<int>({static_cast<int>(iter->second), static_cast<int>(i)});
                }
            }
        }
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums({2, 7, 11, 15});
    Solution so;
    auto result = so.twoSum(nums, 9);
    cout << result[0] << ' ' << result[1] << endl;
    return 0;
}
