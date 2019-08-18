#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
  public:
    bool isValid(string s)
    {
        stack<char> st;
        for (char c : s)
        {
            char expected;
            switch (c)
            {
            case '(':
            case '[':
            case '{':
                st.push(c);
                continue;
            case ')':
                expected = '(';
                break;
            case ']':
                expected = '[';
                break;
            case '}':
                expected = '{';
                break;
            default:
                return false;
            }
            if (st.empty() || expected != st.top())
            {
                return false;
            }
            st.pop();
        }
        return st.empty();
    }
};

int main(int argc, char *argv[])
{
    Solution so;
    cout << so.isValid("()") << endl;
    cout << so.isValid("()[]{}") << endl;
    cout << so.isValid("(]") << endl;
    cout << so.isValid("([)]") << endl;
    cout << so.isValid("{[]}") << endl;
    return 0;
}
