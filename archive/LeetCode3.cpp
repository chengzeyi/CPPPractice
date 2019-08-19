#include <iostream>
#include <cstddef>
#include <vector>
#include <limits>
using namespace std;

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        size_t size = s.size();
        if (size == 0)
        {
            return 0;
        }
        size_t left = 0, right = 0;
        int result = 1;
        vector<bool> occur(128, false);
        while (right < size)
        {
            char rightC = s[right];
            if (!occur[rightC])
            {
                occur[rightC] = true;
            }
            else
            {
                char leftC;
                while ((leftC = s[left]) != rightC)
                {
                    occur[leftC] = false;
                    left++;
                }
                left++;
            }
            int currLength = right - left + 1;
            if (currLength > result)
            {
                result = currLength;
            }
            right++;
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution so;
    cout << so.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << so.lengthOfLongestSubstring("bbbbb") << endl;
    cout << so.lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}
