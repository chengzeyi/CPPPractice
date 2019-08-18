#include "prettyprint.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
  public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        unordered_map<int, size_t> num2Index;
        size_t numbersSize = numbers.size();
        for (size_t i = 0; i < numbersSize; i++)
        {
            if (num2Index.find(target - numbers[i]) != num2Index.end())
            {
                    return vector<int>({(int)num2Index[target - numbers[i]] + 1, (int)i + 1});
            }
            else
            {
                num2Index.emplace(numbers[i], i);
            }
        }
    }
};

int main(int argc, char *argv[])
{
    vector<int> numbers({2, 7, 11, 15});
    auto result = Solution().twoSum(numbers, 9);
    cout << result << endl;
    return 0;
}
