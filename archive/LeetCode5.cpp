#include <iostream>
#include <string>

using namespace std;

class Solution
{
  public:
    string longestPalindrome(string s)
    {
        size_t length = s.size();
        if (length == 0)
        {
            return "";
        }
        size_t resultL = 0, resultR = 0;
        for (size_t i = 0; i < length; i++)
        {
            size_t left = i, right = i;
            while (left != 0 && right != length - 1)
            {
                if (s[left - 1] != s[right + 1])
                {
                    break;
                }
                left--;
                right++;
            }
            if (right - left > resultR - resultL)
            {
                resultL = left;
                resultR = right;
            }
        }
        for (size_t i = 0; i < length - 1; i++)
        {
            size_t left = i, right = i + 1;
            if (s[left] != s[right])
            {
                continue;
            }
            while (left != 0 && right != length - 1)
            {
                if (s[left - 1] != s[right + 1])
                {
                    break;
                }
                left--;
                right++;
            }
            if (right - left > resultR - resultL)
            {
                resultL = left;
                resultR = right;
            }
        }
        return s.substr(resultL, resultR - resultL + 1);
    }
};

int main(int argc, char *argv[])
{
    Solution so;
    cout << so.longestPalindrome("babad") << endl;
    cout << so.longestPalindrome("cbbd") << endl;
    return 0;
}
