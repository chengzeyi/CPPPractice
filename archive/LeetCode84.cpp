#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
  public:
	int largestRectangleArea(vector<int> &heights)
	{
		int maxArea = 0;
		for (int i = 0; i < heights.size(); i++)
		{
			int left = i, right = i, height = heights.at(i);
			while (left > 0 && heights.at(left - 1) >= height)
				left--;
			while (right < heights.size() - 1 && heights.at(right + 1) >= height)
				right++;
			maxArea = max(maxArea, height * (right - left + 1));
		}
		return maxArea;
	}
};

int main(int argc, char *argv[])
{
	vector<int> heights({2, 1, 5, 6, 2, 3});
	Solution so;
	cout << so.largestRectangleArea(heights) << endl;
	return 0;
}
