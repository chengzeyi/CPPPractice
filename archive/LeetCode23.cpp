#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	inline static bool pListNodeLessThan(const ListNode *a, const ListNode *b)
	{
		return a->val < b->val;
	}

public:
	ListNode *mergeKLists(vector<ListNode*>& lists) {
		vector<ListNode *> mergedList;
		for (auto iter = lists.begin(); iter != lists.end(); iter++)
		{
			while (*iter != nullptr)
			{
				mergedList.push_back(*iter);
				*iter = (*iter)->next;
			}
		}
		if (mergedList.size() == 0)
		{
			return nullptr;
		}
		sort(mergedList.begin(), mergedList.end(), pListNodeLessThan);
		for (auto iter = mergedList.begin(); iter != mergedList.end() - 1; iter++)
		{
			(*iter)->next = *(iter + 1);
		}
		mergedList.back()->next = nullptr;
		return mergedList.front();
	}
};

int main(int argc, char *argv[]) {
	ListNode *a1 = new ListNode(1);
	ListNode *a2 = new ListNode(4);
	a1->next = a2;
	ListNode *a3 = new ListNode(5);
	a2->next = a3;

	ListNode *b1 = new ListNode(1);
	ListNode *b2 = new ListNode(3);
	b1->next = b2;
	ListNode *b3 = new ListNode(4);
	b2->next = b3;

	ListNode *c1 = new ListNode(2);
	ListNode *c2 = new ListNode(6);
	c1->next = c2;

	vector<ListNode *> lists({a1, b1, c1});
	Solution s;
	ListNode *pFirst = s.mergeKLists(lists);

	while (pFirst != nullptr)
	{
		cout << pFirst->val << endl;
		pFirst = pFirst->next;
	}

	return 0;
}