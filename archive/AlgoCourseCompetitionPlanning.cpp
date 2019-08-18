#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef vector<int> Row;
typedef vector<Row> Table;

Table plan(int k)
{
    // 根据k，求出n。
    size_t n = 1;
    for (int i = 0; i < k; i++)
    {
        n *= 2;
    }
    // 赛程表的大小以及可以确定了，n-1行，n列。
    Table table(n - 1, Row(n));
    // 按照行优先的顺序生成赛程表。
    for (size_t row = 0; row < n - 1; row++)
    {
        // 为了使选手们错开，并在不同的日子与不同的对手比赛，
        // 考虑设置一个“步长”，该变量每天都进行更新，只有编号之间的距离
        // 等于步长的选手才能进行比赛。
        const size_t step = row + 1;
        for (size_t col = 0; col < n; col++)
        {
            // 按照从左到右的列顺序进行安排，设置该选手的对手的同时也对其对手的对手进行设置
            // 故对于那些col % (step * 2) < step的列，其值已经被设置过了，故可直接跳过。
            if (col % (step * 2) < step)
            {
                // 设置互为对手的两名选手的对手的值，这里用取模的方法来保证下标不会越界。
                table[row][col] = (col + step) % n + 1;
                table[row][(col + step) % n] = col + 1;
            }
        }
    }
    return table;
}

int main(int argc, char *argv[])
{
    cout << "Competitor num: 2^3" << endl;
    Table table = plan(3);
    for (const Row &row : table)
    {
        for (int i : row)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    cout << endl;
    cout << "Competitor num: 2^4" << endl;
    table = plan(4);
    for (const Row &row : table)
    {
        for (int i : row)
        {
            cout << setw(2) << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
