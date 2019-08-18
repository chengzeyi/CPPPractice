#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	void reverse(ListNode *front, ListNode *back)
	{
		ListNode *current = front;
		ListNode *currentNext = front->next;
		while (current != back)
		{
			ListNode *tmp = currentNext->next;
			currentNext->next = current;
			current = currentNext;
			currentNext = tmp;
		}
		front->next = currentNext;
	}

public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (k == 1)
		{
			return head;
		}
		ListNode *front = head;
		ListNode *subFront = head;
		ListNode *last = new ListNode(0);
		int count = 0;
		while (true)
		{
			ListNode *subBack = subFront;
			for (size_t i = 0; i < k - 1; i++)
			{
				if (subBack == nullptr || subBack->next == nullptr)
				{
					return front;
				}
				else
				{
					subBack = subBack->next;
				}
			}
			reverse(subFront, subBack);
			count++;
			if (count == 1)
			{
				front = subBack;
			}
			last->next = subBack;
			last = subFront;
			subFront = subFront->next;
		}
	}
};

int main(int argc, char *argv[]) {
	for (size_t i = 2; i < 4; i++)
	{
		ListNode *a = new ListNode(1);
		ListNode *b = new ListNode(2);
		ListNode *c = new ListNode(3);
		ListNode *d = new ListNode(4);
		ListNode *e = new ListNode(5);
		a->next = b;
		b->next = c;
		c->next = d;
		d->next = e;
		Solution s;
		ListNode *front = s.reverseKGroup(a, i);
		while (front != nullptr)
		{
			cout << front->val << endl;
			front = front->next;
		}
		cout << endl;
	}
	return 0;
}