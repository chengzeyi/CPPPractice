#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
  private:
    static bool myCompare(const Interval &l, const Interval &r)
    {
        return l.start < r.start;
    }

  public:
    vector<Interval> merge(vector<Interval> &intervals)
    {
        sort(intervals.begin(), intervals.end(), myCompare);
        vector<Interval> result;
        size_t intervalsSize = intervals.size();
        if (intervalsSize == 0)
        {
            return result;
        }
        result.push_back(intervals.front());
        for (size_t i = 1; i < intervalsSize; i++)
        {
            const Interval &lastInterval = result.back();
            const Interval &intervalToAdd = intervals[i];
            if (lastInterval.end >= intervalToAdd.start)
            {
                Interval newInterval(lastInterval.start, max(lastInterval.end, intervalToAdd.end));
                result.back() = newInterval;
            }
            else
            {
                result.push_back(intervalToAdd);
            }
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    vector<Interval> intervals({Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 8)});
    auto result = Solution().merge(intervals);
    for (auto &interval : result)
    {
        cout << interval.start << " " << interval.end << endl;
    }
    return 0;
}
