#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    int maxArea(vector<int>& height)
    {
        int maxArea = 0, l = 0, r = height.size() - 1;
        while (l < r)
        {
            maxArea = max(maxArea, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return maxArea;
    }
};

int main(int argc, char *argv[])
{
    vector<int> height({1, 8, 6, 2, 5, 4, 8, 3, 7});
    Solution so;
    cout << so.maxArea(height) << endl;
    return 0;
}
