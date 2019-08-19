#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int removeElement(vector<int> &nums, int val)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != val)
                nums[res++] = nums[i];
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums({0, 1, 2, 2, 3, 0, 4, 2});
    Solution so;
    const int newSize = so.removeElement(nums, 2);
    for (size_t i = 0; i < newSize; i++)
    {
        cout << nums[i] << endl;
    }
    return 0;
}
