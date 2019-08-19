#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution
{
  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        const size_t strSize = s.size(), wordDictSize = wordDict.size();
        vector<bool> visited(strSize, false);
        stack<size_t> strIndices, wordDictIndices; 
        strIndices.push(0);
        wordDictIndices.push(0);
        while (!strIndices.empty())
        {
            const size_t strIndex = strIndices.top();
            size_t &wordDictIndex = wordDictIndices.top();
            bool flag = false;
            while (wordDictIndex < wordDictSize)
            {
                const string &word = wordDict[wordDictIndex];
                const size_t wordSize = word.size();
                wordDictIndex++;
                if (s.substr(strIndex, wordSize) == word)
                {
                    if (strIndex + wordSize == strSize)
                    {
                        return true;
                    }
                    const size_t nextStrIndex = strIndex + wordSize;
                    if (!visited[nextStrIndex])
                    {
                        visited[nextStrIndex] = true;
                        wordDictIndices.push(0);
                        strIndices.push(nextStrIndex);
                        flag = true;
                        break;
                    }
                }
            }
            if (flag)
            {
                continue;
            }
            strIndices.pop();
            wordDictIndices.pop();
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    string s("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
    vector<string> wordDict({"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"});
    cout << Solution().wordBreak(s, wordDict) << endl;
    return 0;
}
