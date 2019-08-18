#include <iostream>

using namespace std;

class Solution
{
  public:
    int numTrees(int n)
    {
        long c = 1;
        for (int i = 0; i < n; i++)
        {
            c = c * 2 * (2 * i + 1) / (i + 2);
        }
        return c;
    }
};

int main(int argc, char *argv[])
{
    cout << Solution().numTrees(3) << endl;
    return 0;
}
