#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    int longestConsecutive(vector<int> &nums)
    {
        const size_t numsSize = nums.size();
        if (numsSize <= 1)
        {
            return numsSize;
        }
        sort(nums.begin(), nums.end());
        int longest = 1, curr = 1, last = nums[0];
        for (size_t i = 1; i < numsSize; i++)
        {
            const int num = nums[i];
            if (num == last + 1)
            {
                curr++;
            }
            else if (num != last)
            {
                curr = 1;
            }
            if (curr > longest)
            {
                longest = curr;
            }
            last = num;
        }
        return longest;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums({100, 4, 200, 1, 3, 2});
    cout << Solution().longestConsecutive(nums) << endl;
    return 0;
}
