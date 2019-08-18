#include <iostream>
#include <string>
#include <vector>

using namespace std;

 struct Interval {
 	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> newIntervals;
		auto iter = intervals.cbegin();
		while(true)
		{
			if (iter == intervals.cend())
			{
				newIntervals.push_back(newInterval);
				break;
			}
			else if (newInterval.end < iter->start)
			{
				newIntervals.push_back(newInterval);
				while (iter != intervals.cend())
				{
					newIntervals.push_back(*iter);
					iter++;
				}
				break;
			}
			else if (newInterval.start < iter->start && newInterval.end >= iter->start && newInterval.end <= iter->end)
			{
				newInterval.end = iter->end;
				iter++;
			}
			else if (newInterval.start >= iter->start && newInterval.end <= iter->end)
			{
				while (iter != intervals.cend())
				{
					newIntervals.push_back(*iter);
					iter++;
				}
				break;
			}
			else if (newInterval.start < iter->start && newInterval.end > iter->end)
			{
				iter++;
			}
			else if (newInterval.start >= iter->start && newInterval.start <= iter->end && newInterval.end > iter->end)
			{
				newInterval.start = iter->start;
				iter++;
			}
			else
			{
				newIntervals.push_back(*iter);
				iter++;
			}
		}
		return newIntervals;
	}
};

int main(int argc, char *argv[]) {
	Solution so;
	vector<Interval> intervals({Interval(1, 2), Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16)});
	auto newIntervals = so.insert(intervals, Interval(4, 8));
	for (auto interval : newIntervals)
	{
		cout << interval.start << ", " << interval.end << endl;
	}
	return 0;
}
