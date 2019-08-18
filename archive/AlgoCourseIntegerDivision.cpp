#include <iostream>
#include <list>

using namespace std;

// 递归例程求正整数的划分。
void divideInteger(int n, int upperBound, const list<int> &division, list<list<int>> &divisions)
{
    // 递归终止条件，该数为0。
    if (n == 0)
    {
        divisions.push_back(division);
        return;
    }
    // upperBound即所能划分到的数的上界，也即先前以及生成的划分序列的最小值，
    // 从1到upperBound，用所生成的数扩充序列，并更新upperBound与n，递归调用例程
    // 生成剩下的部分。
    for (int i = 1; i <= upperBound && i <= n; i++)
    {
        auto nextDivision = division;
        nextDivision.push_back(i);
        divideInteger(n - i, i, nextDivision, divisions);
    }
}

// 递归例程的wrapper，实例化递归例程所需的数据结构。
list<list<int>> divideInteger(int n)
{
    list<int> division;
    list<list<int>> divisions;
    divideInteger(n, n, division, divisions);
    return divisions;
}

int main(int argc, char *argv[])
{
    cout << "Integer: 8" << endl;
    for (auto l : divideInteger(8))
    {
        for (int i : l)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    cout << endl;
    cout << "Integer: 9" << endl;
    for (auto l : divideInteger(9))
    {
        for (int i : l)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
