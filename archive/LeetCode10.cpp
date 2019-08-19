#include <iostream>
#include <string>
#include <utility>
#include <list>

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

	void compile(const string& p)
	{
		cp.clear();
		for (auto iter = p.cbegin(); iter != p.cend(); iter++)
		{
			switch (*iter)
			{
			case '*':
				cp.back().first = ReElemType::ZeroOrMore;
				break;
			default:
				cp.emplace_back(ReElemType::Single, *iter);
				break;
			}
		}
	}

	bool match(string::const_iterator iterS, const string::const_iterator& sEnd, CompiledPattern::const_iterator iterP, const CompiledPattern::const_iterator& pEnd) const
	{
		while (true)
		{
			if (iterP == pEnd)
			{
				if (iterS == sEnd)
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
				switch (iterP->first)
				{
				case ReElemType::Single:
					if (iterS == sEnd)
					{
						return false;
					}
					else if (iterP->second == '.' || iterP->second == *iterS)
					{
						iterS++;
						iterP++;
						continue;
					}
					else
					{
						return false;
					}
					break;
				case ReElemType::ZeroOrMore:
					if (iterS == sEnd)
					{
						iterP++;
						continue;
					}
					else if (iterP->second == '.' || iterP->second == *iterS)
					{
						return match(iterS, sEnd, ++iterP, pEnd) || match(++iterS, sEnd, --iterP, pEnd);
					}
					else
					{
						iterP++;
						continue;
					}
					break;
				default:
					break;
				}
			}
		}
	}

  public:
	bool isMatch(string s, string p) {
		compile(p);
		return match(s.cbegin(), s.cend(), cp.cbegin(), cp.cend());
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	cout << s.isMatch("aa", "a") << endl;
	cout << s.isMatch("aa", "a*") << endl;
	cout << s.isMatch("ab", ".*") << endl;
	cout << s.isMatch("aab", "c*a*b") << endl;
	cout << s.isMatch("mississippi", "mis*is*p") << endl;
	return 0;
}