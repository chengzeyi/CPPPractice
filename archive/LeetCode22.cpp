#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> results;
        if (n == 0)
        {
            return results;
        }
        vector<int> numsRemainedLeft, numsUnpairedLeft;
        results.push_back("(");
        numsRemainedLeft.push_back(n - 1);
        numsUnpairedLeft.push_back(1);
        for (int i = 0; i < 2 * n - 1; i++)
        {
            size_t numResult = results.size();
            for (size_t i = 0; i < numResult; i++)
            {
                const string result = results[i];
                const int numRemainedLeft = numsRemainedLeft[i], numUnpairedLeft = numsUnpairedLeft[i];
                if (numRemainedLeft > 0 && numUnpairedLeft > 0)
                {
                    results.push_back(result + '(');
                    numsRemainedLeft.push_back(numRemainedLeft - 1);
                    numsUnpairedLeft.push_back(numUnpairedLeft + 1);
                }
                if (numUnpairedLeft == 0)
                {
                    results[i] += '(';
                    numsRemainedLeft[i]--;
                    numsUnpairedLeft[i]++;
                }
                else
                {
                    results[i] += ')';
                    numsUnpairedLeft[i]--;
                }
            }
        }
        return results;
    }
};

int main(int argc, char *argv[])
{
    Solution so;
    auto results = so.generateParenthesis(5);
    for (const string &s : results)
    {
        cout << s << endl;
    }
    return 0;
}
