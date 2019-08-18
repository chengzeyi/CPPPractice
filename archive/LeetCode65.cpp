#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
	string inputStr;
	string::const_iterator iter;

	bool matchPlusOrMinus()
	{
		if (iter == inputStr.cend())
		{
			return false;
		}
		if (*iter == '+' || *iter == '-')
		{
			iter++;
			return true;
		}
		return false;
	}

	bool matchNumber()
	{
		if (iter == inputStr.cend())
		{
			return false;
		}
		if (*iter >= '0' && *iter <= '9')
		{
			iter++;
			return true;
		}
		return false;
	}

	bool matchExponent()
	{
		if (iter == inputStr.cend())
		{
			return false;
		}
		if (*iter == 'e')
		{
			iter++;
			return true;
		}
		return false;
	}

	bool matchPoint()
	{
		if (iter == inputStr.cend())
		{
			return false;
		}
		if (*iter == '.')
		{
			iter++;
			return true;
		}
		return false;
	}

	bool matchSpaces()
	{
		if (iter == inputStr.cend())
		{
			return false;
		}
		if (*iter == ' ')
		{
			while (*(++iter) == ' ');
			return true;
		}
		return false;
	}

	bool matchIntPart()
	{
		if (matchNumber())
		{
			while (matchNumber());
			return true;
		}
		return false;
	}

	bool matchDecPart()
	{
		if (matchNumber())
		{
			while (matchNumber());
			return true;
		}
		return false;
	}

	bool matchInt()
	{
		auto saved = iter;
		if (matchPlusOrMinus())
		{
			if (matchIntPart())
			{
				return true;
			}
		}
		else if (matchIntPart())
		{
			return true;
		}
		iter = saved;
		return false;
	}

	bool matchDec()
	{
		auto saved = iter;
		if (matchPlusOrMinus() && matchIntPart() && matchPoint() && matchDecPart())
		{
			return true;
		}
		iter = saved;
		if (matchIntPart() && matchPoint() && matchDecPart())
		{
			return true;
		}
		iter = saved;
		if (matchPlusOrMinus() && matchPoint() && matchDecPart())
		{
			return true;
		}
		iter = saved;
		if (matchPoint() && matchDecPart())
		{
			return true;
		}
		iter = saved;
		if (matchPlusOrMinus() && matchInt() && matchPoint())
		{
			return true;
		}
		iter = saved;
		if (matchInt() && matchPoint())
		{
			return true;
		}
		iter = saved;
		return false;
	}

	bool matchFirst()
	{
		if (matchDec() || matchInt())
		{
			return true;
		}
		return false;
	}

	bool matchSecond()
	{
		auto saved = iter;
		if (matchExponent() && matchInt())
		{
			return true;
		}
		iter = saved;
		return false;
	}

	bool matchValidNumberWithoutSpaces()
	{
		if (matchFirst())
		{
			matchSecond();
			return true;
		}
		return false;
	}

	bool matchValidNumberWithSpaces()
	{
		auto saved = iter;
		matchSpaces();
		if (matchValidNumberWithoutSpaces())
		{
			matchSpaces();
			return true;
		}
		iter = saved;
		return false;
	}

public:
	bool isNumber(string s) {
		inputStr = s;
		iter = s.cbegin();
		if (matchValidNumberWithSpaces() && iter == s.cend())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main(int argc, char *argv[]) {
	Solution so;
	vector<string> inputs({"0", " 0.1 ", "abc", "1 a", "2e10", " -90e3   ", " 1e", "e3", " 6e-1", " 99e2.5 ", "53.5e93", " --6 ", "-+3", "95a54e53"});
	for (auto s : inputs)
	{
		cout << so.isNumber(s) << endl;
	}
	return 0;
}
