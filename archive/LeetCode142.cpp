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
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
        {
            return NULL;
        }
        ListNode *slow = head, *fast = head, *entry = head;
        while (fast->next &&)
        {
            
        }
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
