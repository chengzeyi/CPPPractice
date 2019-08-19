#include "prettyprint.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class Solution
{
  public:
    string fractionToDecimal(long long numerator, long long denominator)
    {
        string result;
        stringstream ss;
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
        {
            ss << '-';
        }
        numerator = abs(numerator);
        denominator = abs(denominator);
        long long intPart = numerator / denominator;
        long long r = numerator % denominator;
        ss << intPart;
        ss >> result;
        if (!r)
        {
            return result;
        }
        unordered_map<long long, size_t> table;
        result += '.';
        while (r)
        {
            if (table.find(r) != table.end())
            {
                size_t index = table.at(r);
                result.insert(index, 1, '(');
                result += ')';
                break;
            }
            else
            {
                table.emplace(r, result.size());
                char toAppend = r * 10 / denominator + '0';
                r = r * 10 % denominator;
                result += toAppend;
            }
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    cout << Solution().fractionToDecimal(-1, -2147483648) << endl;
    return 0;
}
