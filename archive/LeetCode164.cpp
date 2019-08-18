#include "prettyprint.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    int maximumGap(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int last = nums.front(), anwser = 0;
        for (auto iter = nums.cbegin() + 1; iter != nums.cend(); iter++)
        {
            anwser = max(anwser, *iter - last);
            last = *iter;
        }
        return anwser;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums({3, 6, 9, 1});
    cout << Solution().maximumGap(nums) << endl;
    return 0;
}
