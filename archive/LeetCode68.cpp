#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
	vector<string>::const_iterator start, end;
	int maxWidth, charInLineNum;

	string justifyLine()
	{
		string justifiedLine;
		const int wordNum = end - start;
		const int slotNum = wordNum == 1 ? 1 : wordNum - 1;
		const int spaceNum = maxWidth - charInLineNum;
		vector<int> slots(slotNum, 0);
		for (auto& slot : slots)
		{
			slot += spaceNum / slotNum;
		}
		for (int i = 0; i < spaceNum % slotNum; i++)
		{
			slots[i]++;
		}
		for (int i = 0; i < slotNum; i++)
		{
			justifiedLine.append(*(start + i));
			justifiedLine.append(string(slots[i], ' '));
		}
		if (wordNum > slotNum)
		{
			justifiedLine.append(*(start + wordNum - 1));
		}
		return justifiedLine;
	}

	string justifyLastLine()
	{
		string justifiedLastLine;
		int count = 0;
		justifiedLastLine.append(*start);
		count += start->size();
		for (auto iter = start + 1; iter != end; iter++)
		{
			justifiedLastLine.append(" ");
			justifiedLastLine.append(*iter);
			count += (iter->size() + 1);
		}
		justifiedLastLine.append(maxWidth - count, ' ');
		return justifiedLastLine;
	}

public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> result;
		this->maxWidth = maxWidth;
		start = words.cbegin();
		end = start;
		while (true)
		{
			int intensiveWidth = 0;
			charInLineNum = 0;
			while (true)
			{
				if (intensiveWidth + end->size() > this->maxWidth)
				{
					if (end == words.cend())
					{
						result.push_back(justifyLastLine());
						return result;
					}
					else
					{
						result.push_back(justifyLine());
						start = end;
						break;
					}
				}
				else
				{
					intensiveWidth += (end->size() + 1);
					charInLineNum += end->size();
					end++;
				}
			}
		}
	}
};

int main(int argc, char *argv[]) {
	vector<string> words({"This", "is", "an", "example", "of", "text", "justification."});
	Solution so;
	auto result = so.fullJustify(words, 16);
	for (auto lineStr : result)
	{
		cout << '"' << lineStr << '"' << endl; 
	}
	return 0;
}
