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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummyHead(0);
        ListNode *p = l1, *q = l2, *curr = &dummyHead;
        int carry = 0;
        while (p != NULL || q != NULL)
        {
            int x = p != NULL ? p->val : 0;
            int y = q != NULL ? q->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (p != NULL)
                p = p->next;
            if (q != NULL)
                q = q->next;
        }
        if (carry > 0)
            curr->next = new ListNode(carry);
        return dummyHead.next;
    }
};

int main(int argc, char *argv[])
{
    ListNode a1(2), a2(4), a3(3), b1(5), b2(6), b3(4);
    a1.next = &a2;
    a2.next = &a3;
    b1.next = &b2;
    b2.next = &b3;
    Solution so;
    ListNode *result = so.addTwoNumbers(&a1, &b1);
    while (result != NULL)
    {
        cout << result->val << endl;
        result = result->next;
    }
    return 0;
}
