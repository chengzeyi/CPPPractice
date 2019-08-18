#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int climbStairs(int n)
    {
        if (n <= 2)
        {
            return n;
        }
        vector<int> counts(n);
        counts[0] = 1;
        counts[1] = 2;
        for (size_t i = 2; i < n; i++)
        {
            counts[i] = counts[i - 1] + counts[i - 2];
        }
        return counts.back();
    }
};

int main(int argc, char *argv[])
{
    cout << Solution().climbStairs(3) << endl;
    return 0;
}
