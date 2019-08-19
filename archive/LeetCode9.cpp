#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Solution
{
  public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }
        int revertedNumber = 0;
        while (x > revertedNumber)
        {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        return x == revertedNumber || x == revertedNumber / 10;
    }
};

int main(int argc, char *argv[])
{
    Solution so;
    cout << so.isPalindrome(121) << endl;
    cout << so.isPalindrome(-121) << endl;
    cout << so.isPalindrome(10) << endl;
    return 0;
}
