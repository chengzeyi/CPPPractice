#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        size_t numsSize = nums.size();
        if (numsSize < 2)
        {
            return numsSize;
        }
        size_t srcIndex = 1, destIndex = 1;
        int preNum = nums[0];
        while (srcIndex < numsSize)
        {
            const int num = nums[srcIndex];
            if (num != preNum)
            {
                preNum = num;
                nums[destIndex] = num;
                destIndex++;
            }
            srcIndex++;
        }
        return destIndex;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums({0, 0, 1, 1, 1, 2, 2, 3, 3, 4});
    Solution so;
    size_t newSize = so.removeDuplicates(nums);
    for (size_t i = 0; i < newSize; i++)
    {
        cout << nums[i] << endl;
    }
    return 0;
}
