#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
#include <unordered_set>

using namespace std;

class Solution
{
private:
    vector<string> wordBreak(string s, unordered_set<string>& wordSet)
    {
        unordered_map<size_t, vector<string>> memo({
            {s.size(), {""}}
        });
        function<vector<string>(size_t)> sentences = [&](size_t i)
        {
            if (!memo.count(i))
                for (size_t j = i + 1; j <= s.size(); j++)
                    if (wordSet.find(s.substr(i, j - i)) != wordSet.end())
                        for (string tail : sentences(j))
                            memo[i].push_back(s.substr(i, j - i) + (tail == "" ? "" : ' ' + tail));
            return memo[i];
        };
        return sentences(0);
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> wordSet;
        for (auto& str : wordDict)
        {
            wordSet.insert(str);
        }
        return wordBreak(s, wordSet);
    }
};

int main(int argc, char* argv[])
{
    string s = "aaaaaaa";
    vector<string> wordDict = {"aaaa", "aa", "a"};
    auto sentences = Solution().wordBreak(s, wordDict);
    for (auto& sentence : sentences)
    {
        cout << sentence << endl;
    }
    return 0;
}
