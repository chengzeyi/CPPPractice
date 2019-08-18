#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> results;
        unordered_map<int, size_t> keys;
        for (const string &str : strs)
        {
            vector<int> key(26, 0);
            for (char c : str)
            {
                key[c - 'a']++;
            }
            if (keys.)
            {
                
            }
            if (!findFlag)
            {
                keys.push_back(key);
                results.push_back(vector<string>(1, str));
            }
        }
        return results;
    }
};

int main(int argc, char *argv[])
{
    vector<string> strs({"eat", "tea", "tan", "ate", "nat", "bat"});
    Solution so;
    auto results = so.groupAnagrams(strs);
    for (const auto &strs : results)
    {
        for (const auto &str : strs)
        {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
