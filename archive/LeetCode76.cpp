#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	string minWindow(string s, string t)
	{
		unordered_map<char, int> charTotal, windowCounts;
		for (auto c : t)
		{
			if (charTotal.find(c) == windowCounts.end())
			{
				charTotal.emplace(c, 1);
				windowCounts.emplace(c, 0);
			}
			else
			{
				charTotal.at(c)++;
			}
		}
		int l = 0, r = 0, required = charTotal.size(), formed = 0, ans[] = {INT32_MAX, 0, 0};
		while (r < s.length())
		{
			char c = s.at(r);
			if (charTotal.find(c) != charTotal.end())
			{
				windowCounts.at(c)++;
				if (charTotal.at(c) == windowCounts.at(c))
				{
					formed++;
				}
			}
			while (l <= r && formed == required)
			{
				c = s.at(l);
				if (r - l + 1 < ans[0])
				{
					ans[0] = r - l + 1;
					ans[1] = l;
					ans[2] = r;
				}
				if (charTotal.find(c) != charTotal.end())
				{
					if (charTotal.at(c) == windowCounts.at(c))
					{
						formed--;
					}
					windowCounts.at(c)--;
				}
				l++;
			}
			r++;
		}
		return ans[0] == INT32_MAX ? "" : s.substr(ans[1], ans[0]);
	}
};

int main(int argc, char *argv[])
{
	Solution so;
	cout << so.minWindow("abc", "b") << endl;
	return 0;
}
