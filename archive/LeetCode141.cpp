#include <iostream>
#include <limits>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return false;
        }
        else if (head->val == numeric_limits<int>::max())
        {
            return true;
        }
        else
        {
            head->val = numeric_limits<int>::max();
            return hasCycle(head->next);
        }
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
