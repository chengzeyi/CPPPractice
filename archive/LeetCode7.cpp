#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Solution
{
  public:
    int reverse(int x)
    {
        bool minusFlag = false;
        long xLong = x;
        if (xLong < 0)
        {
            minusFlag = true;
            xLong = xLong;
        }
        string tmp = to_string(xLong), tmpRev;
        for (auto iter = tmp.crbegin(); iter != tmp.crend(); iter++)
        {
            tmpRev += *iter;
        }
        long result =  atol(tmpRev.c_str());
        if (minusFlag)
        {
            result = -result;
        }
        if (result > INT32_MAX || result < INT32_MIN)
        {
            result = 0;
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution so;
    cout << so.reverse(123) << endl;
    cout << so.reverse(-123) << endl;
    cout << so.reverse(120) << endl;
    return 0;
}
