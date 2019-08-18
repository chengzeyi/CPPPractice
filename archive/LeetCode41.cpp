#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		size_t arraySize = nums.size();
		vector<bool> table(arraySize + 2, true);
		for(auto var : nums)
		{
			if (var > 0 && var <= arraySize)
			{
				table[var] = false;
			}
		}
		for (size_t i = 1; i < arraySize + 2; i++)
		{
			if (table[i] == true)
			{
				return i;
			}
		}
	}
};

int main(int argc, char *argv[]) {
	vector<int> nums({3, 4, -1 ,1});
	Solution so;
	cout << so.firstMissingPositive(nums) << endl;
	return 0;
}