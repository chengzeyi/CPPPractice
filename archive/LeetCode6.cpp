#include <iostream>
#include <string>

using namespace std;

class Solution
{
  public:
    string convert(string s, int numRows)
    {
        if (numRows < 2)
        {
            return s;
        }
        const size_t strSize = s.size();
        const size_t numCharInBlock = 2 * numRows - 2;
        string result;
        result.reserve(strSize);
        for (size_t i = 0; i < strSize; i += numCharInBlock)
        {
            result.append(1, s[i]);
        }
        for (size_t i = 1; i < numRows - 1; i++)
        {
            size_t j0 = i, j1 = numCharInBlock - i;
            while (j0 < strSize || j1 < strSize)
            {
                if (j0 < strSize)
                {
                    result.append(1, s[j0]);
                    j0 += numCharInBlock;
                }
                if (j1 < strSize)
                {
                    result.append(1, s[j1]);
                    j1 += numCharInBlock;
                }
            }
        }
        for (size_t i = numRows - 1; i < strSize; i += numCharInBlock)
        {
            result.append(1, s[i]);
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution so;
    cout << so.convert("PAYPALISHIRING", 3) << endl;
    cout << so.convert("PAYPALISHIRING", 4) << endl;
    return 0;
}
