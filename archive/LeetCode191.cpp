#include "prettyprint.hpp"
#include <iostream>

using namespace std;

class Solution
{
  public:
    int hammingWeight(uint32_t n)
    {
        int sum = 0;
        while (n)
        {
            sum++;
            n &= (n - 1);
        }
        return sum;
    }
};

int main(int argc, char *argv[])
{
    cout << Solution().hammingWeight(11) << endl;
    return 0;
}
