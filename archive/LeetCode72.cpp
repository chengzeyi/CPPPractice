#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		const int colNum = word1.size() + 1;
		const int rowNum = word2.size() + 1;
		vector<int> dp(colNum * rowNum);
		for (int i = 0; i < colNum; i++)
		{
			dp[i] = i;
		}
		for (int i = 0; i < rowNum; i++)
		{
			dp[i * colNum] = i;
		}
		for (int i = 1; i < rowNum; i++)
		{
			for (int j = 1; j < colNum; j++)
			{
				if (word2[i - 1] == word1[j - 1])
				{
					dp[i * colNum + j] = dp[(i - 1) * colNum + j - 1];
				}
				else
				{
					int left = dp[(i * colNum + j - 1)];
					int upper = dp[(i - 1) * colNum + j];
					int upperLeft = dp[(i - 1) * colNum + j - 1];
					dp[i * colNum + j] = min(left, min(upper, upperLeft)) + 1;
				}
			}
		}
		return dp[colNum * rowNum - 1];
	}
};

int main(int argc, char *argv[]) {
	Solution so;
	cout << so.minDistance("horse", "ros") << endl;
	return 0;
}
