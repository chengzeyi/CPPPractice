#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <ctime>

#define LEFT_BOUND 0.0
#define RIGHT_BOUND 100.0
#define LOWER_BOUND 0.0
#define UPPER_BOUND 100.0

using namespace std;

struct Spot
{
    float x;
    float y;

    Spot(float x, float y) : x(x), y(y) {};
};

typedef vector<Spot> Spots;

// 比较两个点的X轴坐标的大小。
inline bool xAxisCompare(const Spot &a, const Spot &b)
{
    return a.x < b.x;
}

// 计算两个点之间的距离。
inline float calDist(const Spot &a, const Spot &b)
{
    return sqrtf(powf(a.x - b.x, 2.0) + powf(a.y - b.y, 2.0));
}

// 用暴力算法，求解两个不相交的区间上的点之间的最小距离，用于之后使用的分治算法。
float bruteForce(const Spots &sortedSpots, size_t left1, size_t right1, size_t left2, size_t right2)
{
    // 初始化该最短距离为float所能表示的最大值
    float minDist = numeric_limits<float>::max();
    // 枚举出所有的结果。
    for (size_t i = left1; i <= right1; i++)
    {
        for (size_t j = left2; j <= right2; j++)
        {
            float dist = calDist(sortedSpots[i], sortedSpots[j]);
            // 若该距离小于已经求出的最小距离，则更新最小距离。
            if (dist < minDist)
            {
                minDist = dist;
            }
        }
    }
    return minDist;
}

// 采用分治策略的递归算法。
float getMinDist(const Spots &sortedSpots, size_t left, size_t right)
{
    // 递归终止条件，区间内只有一个点，返回float所能表示的最大值。
    if (left == right)
    {
        return numeric_limits<float>::max();
    }
    // 递归终止条件，区间内有两个点，返回这两个点的距离。
    if (left + 1 == right)
    {
        return calDist(sortedSpots[left], sortedSpots[right]);
    }
    // 将该区间分为两部分，[left, leftRight]为左半部分，[rightLeft, right]为右半部分。
    size_t leftRight = (left + right) / 2, rightLeft = leftRight + 1;
    // 递归调用自身，求出左半部分所有点之间的距离的最小值与右半部分所有点之间的距离的最小值。
    float leftMin = getMinDist(sortedSpots, left, leftRight), rightMin = getMinDist(sortedSpots, rightLeft, right);
    // 求出这两个距离之间比较小的那一个。
    float smallerOne = min(leftMin, rightMin);
    // 如果这两个区间之间在X轴上最近的两个点在X轴上的距离大于等于该距离，则可确定在这
    // 两个区间的所有点之间，没有比该距离更小的距离了。
    if (sortedSpots[rightLeft].x - sortedSpots[leftRight].x >= smallerOne)
    {
        return smallerOne;
    }
    // 否则，需要求解这两个区间的所有点之间的距离。易知，该距离必小于之前求到的smallerOne，
    // 因此，只需要确定两个区间之间的中轴线，将中周线两侧到中轴线距离小于smallerOne的点之间的
    // 距离进行比较即可。
    float midBound = (sortedSpots[leftRight].x + sortedSpots[rightLeft].x) / 2.0;
    float leftBound = midBound - smallerOne, rightBound = midBound + smallerOne;
    size_t i = leftRight, j = rightLeft;
    // 确定左侧部分的点。
    while (i > left && sortedSpots[i - 1].x > leftBound) i--;
    // 确定右侧部分的点。
    while (j < right && sortedSpots[j + 1].x < rightBound) j++;
    // 返回smallerOne与对这两个部分之间的点的最小距离进行暴力求解的结果之间的最小值。
    return min(smallerOne, bruteForce(sortedSpots, i, leftRight, rightLeft, j));
}

// 一个wrapper，处理点集大小为0的特殊情况，并对点集按照点的X轴坐标的大小进行排序。
float getMinDist(const Spots &spots)
{
    size_t num = spots.size();
    if (num == 0)
    {
        return numeric_limits<float>::max();
    }
    auto sortedSpots = spots;
    sort(sortedSpots.begin(), sortedSpots.end(), xAxisCompare);
    // 初始化left与right。
    size_t left = 0, right = num - 1;
    return getMinDist(sortedSpots, left, right);
}

int main(int argc, char *argv[])
{
    Spots spots;
    srand(time(nullptr));
    cout << "30 spots" << endl;
    for (size_t i = 0; i < 30; i++)
    {
        float x = LEFT_BOUND + (float)rand() / (float)RAND_MAX * (RIGHT_BOUND - LEFT_BOUND);
        float y = LOWER_BOUND + (float)rand() / (float)(RAND_MAX) * (UPPER_BOUND - LOWER_BOUND);
        spots.emplace_back(x, y);
        cout << '(' << x << ", " << y << ')' << endl;
    }
    cout << getMinDist(spots) << endl;
    return 0;
}
