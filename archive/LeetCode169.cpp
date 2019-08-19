#include "prettyprint.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0, candidate;
        for (int i : nums)
        {
            if (count == 0)
            {
                candidate = i;
            }
            count += (i == candidate) ? 1 : -1;
        }
        return candidate;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums({2, 2, 1, 1, 1, 2, 2});
    cout << Solution().majorityElement(nums) << endl;
    return 0;
}
