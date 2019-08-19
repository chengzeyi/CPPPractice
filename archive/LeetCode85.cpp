#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>

using namespace std;

class Solution
{
  public:
	int maximalRectangle(vector<vector<char>> &matrix)
	{
		if (matrix.size() == 0 || matrix.front().size() == 0)
			return 0;
		int rowNum = matrix.size(), colNum = matrix.front().size(), result = 0;
		vector<int> heights(colNum + 1, 0);
		for (int i = 0; i < rowNum; i++)
		{
			stack<pair<int, int>> st;
			st.emplace(-1, -1);
			matrix[i].push_back('0');
			for (int j = 0; j < colNum + 1; j++)
			{
				if (matrix[i][j] == '0')
					heights[j] = 0;
				else
					heights[j]++;
				int left = j, height = heights[j];
				while (height <= st.top().first)
				{
					left = st.top().second;
					int leftHeight = st.top().first;
					int area = leftHeight * (j - left);
					if (area > result)
						result = area;
					st.pop();
				}
				st.emplace(height, left);
			}
		}
		return result;
	}
};

int main(int argc, char *argv[])
{
	vector<vector<char>> matrix({{'1', '0', '1', '1', '0', '1'},
								 {'1', '1', '1', '1', '1', '1'},
								 {'0', '1', '1', '0', '1', '1'},
								 {'1', '1', '1', '0', '1', '0'},
								 {'0', '1', '1', '1', '1', '1'},
								 {'1', '1', '0', '1', '1', '1'}});
	Solution so;
	cout << so.maximalRectangle(matrix) << endl;
	return 0;
}
