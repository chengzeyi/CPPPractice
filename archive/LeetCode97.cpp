#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
	bool isInterleave(string s1, string s2, string s3)
	{
		size_t n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
		if (n1 + n2 != n3)
			return false;
		vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
		dp[0][0] = true;
		for (size_t i = 1; i <= n1; i++)
			dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
		for (size_t i = 1; i <= n2; i++)
			dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];
		for (size_t i = 1; i <= n1; i++)
			for (size_t j = 1; j <= n2; j++)
				dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i - 1 + j]) || (dp[i][j - 1] && s2[j - 1] == s3[j - 1 + i]);
		return dp[n1][n2];
	}
};

int main(int argc, char *argv[])
{
	Solution so;
	cout << so.isInterleave("bcbccabcccbcbbbcbbacaaccccacbac cabaccbabccbabcaabbbccbbbaa", "ccbccaaccabacaabccaaccbabcbbaacacaccaacbacbbccccbac", "bccbcccabbccaccaccacbacbacbabbcbccbaaccbbaacbcbaacbacbaccaaccabcaccacaacbacbacccbbabcccccbababcaabcbbcccbbbaa") << endl;
	return 0;
}
