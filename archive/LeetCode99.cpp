#include <iostream>
#include <utility>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

class Solution
{
  private:
    TreeNode *pre, *p, *q;

    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;
        dfs(root->left);
        if (pre != nullptr && pre->val > root->val)
        {
            if (p == nullptr)
                p = pre;
            q = root;
        }
        pre = root;
        dfs(root->right);
    }
  public:
    void recoverTree(TreeNode *root)
    {
        pre = p = q = nullptr;
        dfs(root);
        swap(p->val, q->val);
    }
};

int main(int argc, char *argv[])
{
	TreeNode a(1), b(3), c(2);
	a.left = &b;
	b.right = &c;
	Solution so;
	so.recoverTree(&a);
	cout << a.left << ' ' << &a << ' ' << a.right << endl;
	cout << b.left << ' ' << &b << ' ' << b.right << endl;
	cout << c.left << ' ' << &c << ' ' << c.right << endl;
    return 0;
}
