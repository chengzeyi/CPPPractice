#include <iostream>

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode *p = head;
        while (p->next != NULL)
        {
            if (p->next->val == p->val)
            {
                p->next = p->next->next;
            }
            else
            {
                p = p->next;
            }
        }
        return head;
    }
};

int main(int argc, char *argv[])
{
    ListNode n0(1), n1(1), n2(2), n3(3), n4(3);
    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    ListNode *h = Solution().deleteDuplicates(&n0);
    while (h != NULL)
    {
        cout << h->val << endl;
        h = h->next;
    }
    return 0;
}
