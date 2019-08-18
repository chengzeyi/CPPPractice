#include <iostream>

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
  private:
    bool isMirror(TreeNode *t1, TreeNode *t2)
    {
        if (t1 == NULL && t2 == NULL)
        {
            return true;
        }
        if (t1 == NULL || t2 == NULL)
        {
            return false;
        }
        return t1->val == t2->val && isMirror(t1->right, t2->left) && isMirror(t1->left, t2->right);
    }

  public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        return isMirror(root->left, root->right);
    }
};

int main(int argc, char *argv[])
{
    TreeNode t0(1), t1(2), t2(2), t3(3), t4(4), t5(4), t6(3);
    t0.left = &t1;
    t0.right = &t2;
    t1.left = &t3;
    t1.right = &t4;
    t2.left = &t5;
    t2.right = &t6;
    cout << Solution().isSymmetric(&t0) << endl;
    return 0;
}
