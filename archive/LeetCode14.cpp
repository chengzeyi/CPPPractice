#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string result;
        if (strs.size() == 0)
        {
            return result;
        }
        size_t index = 0;
        const string &str0 = strs[0];
        const size_t str0Size = str0.size();
        while (index < str0Size)
        {
            char c = str0[index];
            for (const string &str : strs)
            {
                if (str[index] != c)
                {
                    return result;
                }
            }
            result += c;
            index++;
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    vector<string> strs({"flower", "flow", "flight"});
    Solution so;
    cout << so.longestCommonPrefix(strs) << endl;
    return 0;
}
