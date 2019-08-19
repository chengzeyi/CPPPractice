#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == NULL)
        {
            return vector<int>();
        }
        vector<int> result;
        stack<TreeNode *> nodes;
        stack<int> states;
        nodes.push(root);
        states.push(0);
        while (!nodes.empty())
        {
            TreeNode *topNode = nodes.top();
            int &topState = states.top();
            switch (topState)
            {
            case 0:
                topState = 1;
                if (topNode->left != NULL)
                {
                    nodes.push(topNode->left);
                    states.push(0);
                }
                break;
            case 1:
                topState = 2;
                result.push_back(topNode->val);
                if (topNode->right != NULL)
                {
                    nodes.push(topNode->right);
                    states.push(0);
                }
                break;
            case 2:
                nodes.pop();
                states.pop();
                break;
            default:
                break;
            }
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    TreeNode n0(1), n1(2), n2(3);
    n0.right = &n1;
    n1.left = &n2;
    auto result = Solution().inorderTraversal(&n0);
    for (int i : result)
    {
        cout << i << endl;
    }
    return 0;
}
