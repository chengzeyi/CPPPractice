#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
	int totalCount = 0;

	void find(vector<int>& board, int n)
	{
		int currentRowNum = board.size();
		if (currentRowNum == n)
		{
			totalCount++;
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
	int totalNQueens(int n) {
		vector<int> board;
		find(board, n);
		return totalCount;
	}
};

int main(int argc, char *argv[]) {
	Solution so;
	cout << so.totalNQueens(10) << endl;
	return 0;
}
