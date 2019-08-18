#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int maxAns = 0;
		stack<int> st;
		st.push(-1);
		for (int i = 0; i < s.length(); i++)
		{
			if (s.at(i) == '(')
			{
				st.push(i);
			}
			else
			{
				st.pop();
				if (st.empty())
				{
					st.push(i);
				}
				else
				{
					maxAns = max(maxAns, i - st.top());
				}
			}
		}
		return maxAns;
	}
};

int main(int argc, char *argv[]) {
	string s("(()(((()");
	Solution so;
	cout << so.longestValidParentheses(s) << endl;
	return 0;
}