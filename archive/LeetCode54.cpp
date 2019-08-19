#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        const size_t m = matrix.size();
        if (m == 0)
        {
            return vector<int>();
        }
        const size_t n = matrix.front().size();
        vector<int> result(m * n);
        size_t upper = 0, right = n - 1, lower = m - 1, left = 0, index = 0, currRow = 0, currCol = 0;
        while (index < m * n)
        {
            result[index] = matrix[currRow][currCol];
            if (currRow == upper + 1 && currCol == left && left != right)
            {
                upper++;
                right--;
                lower--;
                left++;
                currCol++;
            }
            else if ((currRow == upper && currCol != right) || upper == lower)
            {
                currCol++;
            }
            else if ((currCol == right && currRow != lower) || right == left)
            {
                currRow++;
            }
            else if (currRow == lower && currCol != left)
            {
                currCol--;
            }
            else
            {
                currRow--;
            }
            index++;
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution so;
    vector<vector<int>> matrix({{7}, {9}, {6}});
    auto result = so.spiralOrder(matrix);
    for (int i : result)
    {
        cout << i << endl;
    }
    return 0;
}
