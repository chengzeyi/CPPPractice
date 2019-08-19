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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy, *q = &dummy;
        for (int i = 0; i < n; i++)
        {
            q = q->next;
        }
        while (q->next != NULL)
        {
            q = q->next;
            p = p->next;
        }
        ListNode *tmp = p->next;
        p->next = tmp->next;
        return dummy.next;
    }
};

int main(int argc, char *argv[])
{
    ListNode n0(1), n1(2), n2(3), n3(4), n4(5);
    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    Solution so;
    ListNode *h = so.removeNthFromEnd(&n0, 2);
    while (h != NULL)
    {
        cout << h->val << endl;
        h = h->next;
    }
    return 0;
}
