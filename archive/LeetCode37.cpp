#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
private:
	vector<vector<char>> *board;
	size_t i, j;
	bool solve()
	{
		if (i == 9)
		{
			return true;
		}
		if ((*board)[i][j] == '.')
		{
			unordered_map<char, bool> isRemained;
			size_t blockRow = i / 3 * 3, blockCol = j / 3 * 3;
			for (char c = '1'; c <= '9'; c++)
			{
				isRemained.emplace(c, true);
			}
			for (size_t k = 0; k < 9; k++)
			{
				char c = (*board)[i][k];
				if (c != '.')
				{
					isRemained.at(c) = false;
				}
				c = (*board)[k][j];
				if (c != '.')
				{
					isRemained.at(c) = false;
				}
				c = (*board)[blockRow + k / 3][blockCol + k % 3];
				if (c != '.')
				{
					isRemained.at(c) = false;
				}
			}
			size_t savedI = i, savedJ = j;
			i = j == 8 ? i + 1 : i;
			j = j == 8 ? 0: j + 1;
			for (const auto& p : isRemained)
			{
				if (p.second == false)
				{
					continue;
				}
				(*board)[savedI][savedJ] = p.first;
				if (solve())
				{
					return true;
				}
			}
			(*board)[savedI][savedJ] = '.';
			i = savedI;
			j = savedJ;
			return false;
		}
		else
		{
			size_t savedI = i, savedJ = j;
			i = j == 8 ? i + 1 : i;
			j = j == 8 ? 0: j + 1;
			if (solve())
			{
				return true;
			}
			else
			{
				i = savedI;
				j = savedJ;
				return false;
			}
		}
	}

public:
	void solveSudoku(vector<vector<char>> &board)
	{
		i = j = 0;
		this->board = &board;
		solve();
	}
};

int main(int argc, char *argv[])
{
	vector<vector<char>> puzzle({
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}});
	Solution so;
	so.solveSudoku(puzzle);
	for (const auto& line : puzzle)
	{
		for (char c : line)
		{
			cout << c << ' ';
		}
		cout << endl;
	}
	return 0;
}
