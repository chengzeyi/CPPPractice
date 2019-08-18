#include <iostream>
#include <string>
#include <list>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <climits>

using namespace std;

class Solution {
private:
	enum ReElemType
	{
		Single,
		ZeroOrMore
	};
	typedef pair<ReElemType, char> ReElem;
	typedef list<ReElem> CompiledPattern;

	CompiledPattern cp;

	unordered_map<char, unordered_set<int>> failureTable;

	void compile(const string& p)
	{
		char count = CHAR_MIN;
		cp.clear();
		for (auto iter = p.cbegin(); iter != p.cend(); iter++)
		{
			switch (*iter)
			{
			case '*':
				if (cp.back().first != ReElemType::ZeroOrMore)
				{
					cp.emplace_back(ReElemType::ZeroOrMore, count);
					count++;
				}
				break;
			default:
				cp.emplace_back(ReElemType::Single, *iter);
				break;
			}
		}
	}

	bool match(string& s, int i, int l, CompiledPattern::const_iterator iter, CompiledPattern::const_iterator end)
	{
		while (true)
		{
			if (iter == end)
			{
				if (i == l)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				switch (iter->first)
				{
				case ReElemType::Single:
					if (i == l)
					{
						return false;
					}
					else if (iter->second == '?' || iter->second == s[i])
					{
						i++;
						iter++;
						continue;
					}
					else
					{
						return false;
					}
					break;
				case ReElemType::ZeroOrMore:
					if (i == l)
					{
						iter++;
						continue;
					}
					else
					{
						if (failureTable[iter->second].find(i) != failureTable[iter->second].end())
						{
							return false;
						}
						else if (match(s, i, l, ++iter, end) || match(s, ++i, l, --iter, end))
						{
							return true;
						}
						else
						{
							failureTable[iter->second].insert(i - 1);
							return false;
						}
					}
					break;
				default: break;
				}
			}
		}
	}

  public:
	bool isMatch(string s, string p) {
		compile(p);
		failureTable.clear();
		return match(s, 0, s.size(), cp.cbegin(), cp.cend());
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb") << endl;
	return 0;
}
