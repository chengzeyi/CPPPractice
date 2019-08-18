#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
  public:
    double myPow(double x, int n)
    {
        return pow(x, n);
    }
};

int main(int argc, char *argv[])
{
    Solution so;
    cout << so.myPow(2.00000, 10) << endl;
    cout << so.myPow(2.10000, 3) << endl;
    cout << so.myPow(2.00000, -1) << endl;
    return 0;
}
