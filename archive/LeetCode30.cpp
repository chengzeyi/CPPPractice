#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
		if (words.size() == 0 || words[0].length() == 0)
		{
			return result;
		}
		size_t wordLength = words[0].length();
		size_t wordNum = words.size();
		unordered_map<string, pair<size_t, size_t>> remainingWords;
		for (auto iter = words.cbegin(); iter != words.cend(); iter++)
		{
			auto iterM = remainingWords.find(*iter);
			if (iterM == remainingWords.end())
			{
				remainingWords.insert(pair<string, pair<size_t, size_t>>(*iter, pair<size_t, size_t>(1, 0)));
			}
			else
			{
				remainingWords[*iter].first++;
			}
		}
		for (size_t i = 0; i < s.length(); i++)
		{
			for(auto iter = remainingWords.begin(); iter != remainingWords.end(); iter++)
			{
				iter->second.second = 0;
			}
			for (size_t count = 0; count < wordNum; count++)
			{
				string substr = s.substr(i + count * wordLength, wordLength);
				auto iter = remainingWords.find(substr);
				if (iter != remainingWords.end() && (iter->second.first != iter->second.second))
				{
					iter->second.second++;
				}
				else
				{
					break;
				}
				if (count + 1 == wordNum)
				{
					result.push_back(i);
				}
			}
		}
		return result;
	}
};

int main(int argc, char *argv[]) {
	string s("barfoothefoobarman");
	vector<string> words({"foo", "bar"});
	Solution so;
	vector<int> result = so.findSubstring(s, words);
	for(auto var : result)
	{
		cout << var << endl;
	}
	return 0;
}