#include "prettyprint.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution
{
  private:
    static bool compare(string &a, string &b)
    {
        string order1 = a + b;
        string order2 = b + a;
        return order1 < order2;
    }

  public:
    string largestNumber(vector<int> &nums)
    {
        stringstream ss;
        size_t numsSize = nums.size();
        vector<string> strs(numsSize);
        for (size_t i = 0; i < numsSize; i++)
        {
            ss << nums[i] << endl;
            ss >> strs[i];
        }
        sort(strs.begin(), strs.end(), compare);
        if (strs.back() == "0")
        {
            return "0";
        }
        string result;
        for (auto iter = strs.crbegin(); iter != strs.crend(); iter++)
        {
            result += *iter;
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums({3, 30, 34, 5, 9});
    cout << Solution().largestNumber(nums) << endl;
    return 0;
}
