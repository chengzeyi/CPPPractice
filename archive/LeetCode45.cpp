#include <iostream>
#include <vector>
#include <cstddef>
#include <algorithm>

using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int times = 0, start = 0, end = 0;
		while (end < nums.size() - 1)
		{
			int endNext = end + 1;
			times++;
			for (int i = start; i <= end; i++)
			{
				endNext = max(endNext, nums[i] + i);
			}
			start = end + 1;
			end = endNext;
		}
		return times;
	}
};

int main(int argc, char *argv[]) {
	vector<int> nums({2, 3, 1, 1, 4});
	Solution so;
	cout << so.jump(nums) << endl;
	return 0;
}