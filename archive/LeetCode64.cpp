#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    int minPathSum(vector<vector<int>> &grid)
    {
        const size_t rowNum = grid.size();
        if (rowNum == 0)
        {
            return 0;
        }
        const size_t colNum = grid.front().size();
        if (colNum == 0)
        {
            return 0;
        }
        for (size_t i = 1; i < rowNum; i++)
        {
            grid[i][0] += grid[i - 1][0];
        }
        for (size_t i = 1; i < colNum; i++)
        {
            grid[0][i] += grid[0][i - 1];
        }
        for (size_t i = 1; i < rowNum; i++)
        {
            for (size_t j = 1; j < colNum; j++)
            {
                grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
            }
        }
        return grid.back().back();
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int>> grid({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}});
    cout << Solution().minPathSum(grid) << endl;
    return 0;
}
