#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
    }
};

int main(int argc, char *argv[])
{
    TreeNode t0(3), t1(9), t2(20), t3(15), t4(7);
    t0.left = &t1;
    t0.right = &t2;
    t2.left = &t3;
    t2.right = &t4;
    cout << Solution().maxDepth(&t0) << endl;
    return 0;
}
