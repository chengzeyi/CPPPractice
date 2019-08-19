#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
	vector<vector<string>> results;

	void find(vector<int>& board, int n)
	{
		int currentRowNum = board.size();
		if (currentRowNum == n)
		{
			vector<string> result;
			for (auto col : board)
			{
				string thisLine;
				for (int i = 0; i < col; i++)
				{
					thisLine += '.';
				}
				thisLine += 'Q';
				for (int i = col + 1; i < n; i++)
				{
					thisLine += '.';
				}
				result.push_back(thisLine);
			}
			results.push_back(result);
		}
		else
		{
			vector<bool> usable(n, true);
			for (int i = 0; i < currentRowNum; i++)
			{
				int col = board[i];
				usable[col] = false;
				if (col + currentRowNum - i < n)
				{
					usable[col + currentRowNum - i] = false;
				}
				if (col - (currentRowNum - i) >= 0)
				{
					usable[col - (currentRowNum - i)] = false;
				}
			}
			for (int i = 0; i< n; i++)
			{
				if (usable[i])
				{
					board.push_back(i);
					find(board, n);
				}
			}
		}
		board.pop_back();
	}

public:
	vector<vector<string>> solveNQueens(int n) {
		vector<int> board;
		find(board, n);
		return results;
	}
};

int main(int argc, char *argv[]) {
	Solution so;
	auto results = so.solveNQueens(10);
	for (const auto& result : results)
	{
		for (const auto& lineInfo : result)
		{
			cout << lineInfo << endl;
		}
		cout << endl;
	}
	return 0;
}
