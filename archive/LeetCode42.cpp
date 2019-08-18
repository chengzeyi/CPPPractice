#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		int liquidCount = 0, highest = 0, heightSize = height.size();
		size_t lastIndex = 0;
		for (int i = 0; i < heightSize; i++)
		{
			if (height[i] >= highest)
			{
				for (int j = lastIndex + 1; j < i; j++)
				{
					liquidCount += highest - height[j];
					height[j] = highest;
				}
				highest = height[i];
				lastIndex = i;
			}
		}
		highest = 0;
		lastIndex = heightSize - 1;
		for (int i = heightSize - 1; i >= 0; i--)
		{
			if (height[i] >= highest)
			{
				for (int j = lastIndex - 1; j > i; j--)
				{
					liquidCount += highest - height[j];
					height[j] = highest;
				}
				highest = height[i];
				lastIndex = i;
			}
		}
		return liquidCount;
	}
};

int main(int argc, char *argv[]) {
	vector<int> height({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});
	Solution s;
	cout << s.trap(height) << endl;
	return 0;
}