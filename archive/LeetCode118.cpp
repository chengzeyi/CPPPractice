#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> pascal;
        if (numRows == 0)
        {
            return pascal;
        }
        pascal.push_back(vector<int>({1}));
        for (size_t i = 1; i < numRows; i++)
        {
            pascal.push_back(vector<int>(i + 1));
            auto &thisLine = pascal[i], &lastLine = pascal[i - 1];
            thisLine.front() = 1;
            thisLine.back() = 1;
            for (size_t j = 1; j < i; j++)
            {
                thisLine[j] = lastLine[j - 1] + lastLine[j];
            }
        }
        return pascal;
    }
};

int main(int argc, char *argv[])
{
    auto pascal = Solution().generate(5);
    for (const auto &line : pascal)
    {
        for (int i : line)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
