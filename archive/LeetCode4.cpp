#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
private:
	double find(vector<int>& nums1, vector<int>& nums2, size_t destIndex)
	{
		if (destIndex < nums1.size() && nums2[0] >= nums1[destIndex])
		{
			return nums1[destIndex];
		}
		if (destIndex < nums2.size() && nums1[0] >= nums2[destIndex])
		{
			return nums2[destIndex];
		}
		size_t maxIndex1 = destIndex >= nums1.size() ? nums1.size() - 1 : destIndex - 1;
		size_t maxIndex2 = destIndex >= nums2.size() ? nums2.size() - 1 : destIndex - 1;
		size_t minIndex1 = destIndex - maxIndex2 - 1;
		while (true)
		{
			size_t endIndex1 = (minIndex1 + maxIndex1) / 2;
			size_t endIndex2 = destIndex - endIndex1 - 1;
			if (minIndex1 == maxIndex1)
			{
				return max(nums1[endIndex1], nums2[endIndex2]);
			}
			if (nums1[endIndex1] > nums2[endIndex2] && endIndex2 + 1 <= maxIndex2 && nums1[endIndex1] > nums2[endIndex2 + 1])
			{
				maxIndex1 = endIndex1 - 1;
			}
			else if (nums1[endIndex1] < nums2[endIndex2] && endIndex1 + 1 <= maxIndex1 && nums2[endIndex2] > nums1[endIndex1 + 1])
			{
				minIndex1 = endIndex1 + 1;
			}
			else
			{
				return max(nums1[endIndex1], nums2[endIndex2]);
			}
		}
	}

public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		size_t nums1Length = nums1.size();
		size_t nums2Length = nums2.size();
		if (nums1Length == 0)
		{
			if (nums2Length % 2 == 0)
			{
				return 1.0 * (nums2[nums2Length / 2 -1] + nums2[nums2Length / 2]) / 2;
			}
			else
			{
				return 1.0 * nums2[nums2Length / 2];
			}
		}
		else if (nums2Length == 0)
		{
			if (nums1Length % 2 == 0)
			{
				return 1.0 * (nums1[nums1Length / 2 -1] + nums1[nums1Length / 2]) / 2;
			}
			else
			{
				return 1.0 * nums1[nums1Length / 2];
			}
		}
		if ((nums1Length + nums2Length) % 2 == 1)
		{
			return 1.0 * find(nums1, nums2, (nums1Length + nums2Length) / 2);
		}
		else
		{
			return 1.0 * (find(nums1, nums2, (nums1Length + nums2Length) / 2 - 1) + find(nums1, nums2, (nums1Length + nums2Length) / 2)) / 2;
		}
    }
};

int main(int argc, char *argv[]) {
	Solution s;
	
	vector<int> a({3, 4}), b({1, 2});
	cout << s.findMedianSortedArrays(a, b) << endl;
	return 0;
}